#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>


#if defined(__x86_64__) || defined(__aarch64__)
#define int long
#endif  

char *freep, *p, *lp; //current position in source code
char *freedata, *data, *_data; //data/bss pointer

int src;//print source
int elf;//print ELF(The Executable and Linkable Format) format

int *le,*e,*text;//current position in emitted code
int *tsize; //array (indexed by type) of type sizes
int tk; //curnet token
int ival; // current token value
int line; //current line number

struct ident_s{
    int tk; //keyword;
    int hash;
    char *name; // name of identifier
    /*
        有h的變數是設計來save和restore global class/type/val，
        當函式宣告和local變數一樣
    */
    int class,hclass;//func,global and local variable,syscall
    int type,htype;//data type such as int and char
    int val,hval;
    int stype;
}*id,//current parsed identifier
*sym;//symbol table

struct members_s{
    struct ident_s *id;
    int offset;
    int type;
    struct member_s *next;
}**members; // array (indexed by type) of struct member lists

// (library) extenral functions
struct ef_s{
    char *name;
    int addr;
}**ef_cache;
int ef_count;


// tokens and classes (operators last and in precedence order)
// ( >= 128 so not to collide with ASCII-valued tokens)
enum {
    Num = 128, // the character set of given source is limited to 7-bit ASCII
    Func, Syscall, Main, ClearCache, Glo, Par, Loc, Keyword, Id, Label, Load, Enter,
    Break, Continue, Case, Char, Default, Else, Enum, If, Int, Return,
    Sizeof, Struct, Union, Switch, For, While, DoWhile, Goto,
    Assign, // operator =, keep Assign as highest priority operator
    OrAssign, XorAssign, AndAssign, ShlAssign, ShrAssign, // |=, ^=, &=, <<=, >>=
    AddAssign, SubAssign, MulAssign, DivAssign, ModAssign, // +=, -=, *=, /=, %=
    Cond, // operator: ?
    Lor, Lan, Or, Xor, And, // operator: ||, &&, |, ^, &
    Eq, Ne, Lt, Gt, Le, Ge, // operator: ==, !=, <, >, <=, >=
    Shl, Shr, Add, Sub, Mul, Div, Mod, // operator: <<, >>, +, -, *, /, %
    Inc, Dec, Dot, Arrow, Bracket, // operator: ++, --, ., ->, [
};


enum {CHAR , INT , PTR=256, PTR2 = 512 };

//elf generation
char **plt_func_addr;
char *freebuf;

enum {
    LEA , /*  0 */
    /* LEA addressed the problem how to fetch arguments inside sub-function.
     * Let's check out what a calling frame looks like before learning how
     * to fetch arguments (Note that arguments are pushed in its calling
     * order):
     *
     *     sub_function(arg1, arg2, arg3);
     *
     *     |    ....       | high address
     *     +---------------+
     *     | arg: 1        |    new_bp + 4
     *     +---------------+
     *     | arg: 2        |    new_bp + 3
     *     +---------------+
     *     | arg: 3        |    new_bp + 2
     *     +---------------+
     *     |return address |    new_bp + 1
     *     +---------------+
     *     | old BP        | <- new BP
     *     +---------------+
     *     | local var 1   |    new_bp - 1
     *     +---------------+
     *     | local var 2   |    new_bp - 2
     *     +---------------+
     *     |    ....       |  low address
     *
     * If we need to refer to arg1, we need to fetch new_bp + 4, which can not
     * be achieved by restricted ADD instruction. Thus another special
     * Instruction is introduced to do this: LEA <offset>.
     * The following pseudocode illustrates how LEA works.
     *     if (op == LEA) { ax = (int) (bp + *pc++); } // load address for arguments
     * Together with JSR, ENT, ADJ, LEV, and LEA instruction, we are able to make
     * function calls.
     */

    IMM , /*  1 */
    /* IMM <num> to put immediate <num> into general register */

    JMP , /*  2 */
    /* JMP <addr> will unconditionally set the value PC register to <addr> */
    /* The following pseudocode illustrates how JMP works:
     *     if (op == JMP) { pc = (int *) *pc; } // jump to the address
     * Note that PC points to the NEXT instruction to be executed. Thus *pc
     * stores the argument of JMP instruction, i.e. the <addr>.
     */

    JSR , /*  3 */
    /* A function is a block of code, which may be far from the instruction
     * we are currently executing. That is reason why JMP instruction exists,
     * jumping into starting point of a function. JSR is introduced to perform
     * some bookkeeping: store the current execution position so that the
     * program can resume after function call returns.
     *
     * JSR <addr> to invoke the function whose starting point is <addr> and
     * LEV to fetch the bookkeeping information to resume previous execution.
     */

    BZ  , /*  4 : conditional jump if general register is zero (jump-if-zero) */
    BNZ , /*  5 : conditional jump if general register is not zero */

    ENT , /*  6 */
    /* ENT <size> is called when we are about to enter the function call to
     * "make a new calling frame". It will store the current PC value onto
     * the stack, and save some space(<size> bytes) to store the local
     * variables for function.
     */

    ADJ , /*  7 */
    /* ADJ <size> is to adjust the stack, to "remove arguments from frame"
     * The following pseudocode illustrates how ADJ works:
     *     if (op == ADJ) { sp += *pc++; } // add esp, <size>
     */

    LEV , /*  8 */
    /* LEV fetches bookkeeping info to resume previous execution.
     * There is no POP instruction in our design, and the following pseudocode
     * illustrates how LEV works:
     *     if (op == LEV) { sp = bp; bp = (int *) *sp++;
     *                      pc = (int *) *sp++; } // restore call frame and PC
     */

    LI  , /*  9 */
    /* LI loads an integer into general register from a given memory
     * address which is stored in general register before execution.
     */

    LC  , /* 10 */
    /* LC loads a character into general register from a given memory
     * address which is stored in general register before execution.
     */

    SI  , /* 11 */
    /* SI stores the integer in general register into the memory whose
     * address is stored on the top of the stack.
     */

    SC  , /* 12 */
    /* SC stores the character in general register into the memory whose
     * address is stored on the top of the stack.
     */

    PSH , /* 13 */
    /* PSH pushes the value in general register onto the stack */

    OR  , /* 14 */  XOR , /* 15 */  AND , /* 16 */
    EQ  , /* 17 */  NE  , /* 18 */
    LT  , /* 19 */  GT  , /* 20 */  LE  , /* 21 */ GE  , /* 22 */
    SHL , /* 23 */  SHR , /* 24 */
    ADD , /* 25 */  SUB , /* 26 */  MUL , /* 27 */ DIV, /* 28 */ MOD, /* 29 */
    /* arithmetic instructions
     * Each operator has two arguments: the first one is stored on the top
     * of the stack while the second is stored in general register.
     * After the calculation is done, the argument on the stack will be poped
     * out and the result will be stored in general register.
     * So you are not able to fetch the first argument from the stack after
     * the calculation.
     */
    SYSC, /* 30 system call */
    CLCA, /* 31 clear cache, used by JIT compilation */
    INVALID
};


void die(char *msg){
    printf("%s\n",msg);
    exit(1);
}


void next(){
    char *pp;

    //用loop來忽略space,也不能被lexical analyzer辨識的字原有@和$

    while ((tk=*p)){
        ++p;
        if ((tk>='a'&& tk <= 'z') || (tk>='A' && tk<='Z') || (tk=='_')){
            pp=p-1;
            while ((*p>='a' && *p <='z')||(*p>='A'&& *p<='Z')||(*p>='0' && *p<='9') || (*p=='_')){
                tk = tk *147 + *p++; //147 is generating hash value
            }
            tk = (tk << 6)+(p-pp); //hash plus symbol length

            //hash value used for fast comparsion
            //have to validdate the memory content as well
            for (id = sym ; id->tk ; id++){//find one free slot in table
                if (tk == id->hash && ! memcmp(id->name,pp,p-pp)){ //if token is found(hash match) ,overwrite
                    tk = id->tk;
                    return;
                }
            }

            //existing symbol name is not found. 
            // id points to the first unused symbol table entry
            id->name=pp;
            id->hash=tk;
            tk = id->tk = id;
            
        }

        //calculate the constant
        //first byte number ,and it is consider a numerical value
        else if (tk>='0'&&tk<='9'){
            /* parse with 3 conditions
                1.not starting with 0:deciaml number
                2.strting with 0x:hex number
                3.starting with 0:octal number
            */
            
            if ((ival=tk-'0')){
                while (*p>='0' && *p<='9'){
                    ival=ival*10+*p++-'0';
                }
            }
            //first digit is 0 and starting with 'x',and it is considered to be a hexadecimal number
            else if (*p=='x'||*p=='X'){
                while ((tk=*++p)&&((tk>='0'&&tk<='9')||(tk>='a'&&tk<='f')||(tk>='A'&&tk<='F'))){
                    ival=ival*16+(tk&15)+(tk>='A'?9:0);
                    
                }
            }else{ //considered octal
                while (*p>='0'&&*p<='7'){
                    ival=ival*8+*p++-'0';
                }
                tk=Num;
                return;
            }
        }

        switch (tk)
        {
        case '\n':
            if (src){
                int *base=le;  
                printf("%d: %.*s",line,p-lp,lp);  
                lp=p;
                while (le<e){
                    int off=le-base; //func IR instruction memory offset
                    printf("%04d: %8.4s", off,
                        & "LEA  IMM  JMP  JSR  BZ   BNZ  ENT  ADJ  LEV  "
                          "LI   LC   SI   SC   PSH  "
                          "OR   XOR  AND  EQ   NE   LT   GT   LE   GE   "
                          "SHL  SHR  ADD  SUB  MUL  DIV  MOD  "
                          "SYSC CLCA" [*++le * 5]);
                    if (*le<=ADJ){
                        ++le;
                        if (*le > (int)base && * le<=(int)e){
                            printf(" %04d\n",off+((*le-(int)le)>>2)+1);
                        }
                        else{
                            printf(" %d\n",*le);
                        }
                    }
                    else if (*le==SYSC){
                        printf(" %s\n",ef_cache[*(++le)]->name);
                    }
                    else{
                        printf("\n");
                    }
                    
                }    
            } 
            ++line; 
            case ' ':
            case '\t':
            case '\v':
            case '\f':
            case '\r':
                break;  
            case '/':
            if (*p=='/'){ //cooment
                case '#':
                    while (*p!=0 && *p!='\n') ++p;
            }else if (*p=='*'){
                int t=0;
                for (++p;(*p!=0) && (t==0);++p){
                    pp=p+1;
                    if (*p=='\n') line++;
                    else if (*p=='*'&&*pp=='/') t=1;
                }
                ++p;
            }else{
                if (*p=='=') {++p;tk=DivAssign;}
                else tk=Div;return;
            }
            break;
        
        case '\'':
        case '"':
            pp=data;

            while (*p!=0 && *p!=tk){
                if ((ival=*p++)=='\\'){
                    switch (ival=*p++)
                    {
                    case 'n':ival='\n';break;
                    case 't':ival='\t';break;
                    case 'v':ival ='\v';break;
                    case 'f':ival='\f';break;
                    case 'r':ival='\r';break;
                    case '0':ival='\0';break;
                    }
                }

                if (tk=='"') *data++=ival;
            }

            ++p;
            
            if (tk=='"') ival=(int)pp;else tk=Num;
            return;

        case '=': if (*p=='=') {++p;tk=Eq;} else tk=Assign;return;
        case '+': if (*p=='+') {++p;tk=Inc;}
                    else if (*p=='=') {++p;tk=AddAssign;}
                    else tk=Add;return;
        case '-': if (*p=='-') {++p;tk=Dec;}
                else if (*p=='>') {++p;tk=Arrow;}
                else if (*p=='=') {++p;tk=SubAssign;}
                else tk=Sub;return;
        case '!': if (*p=='=') {++p;tk=Ne;} return;
        case '<': if (*p=='=') {++p;tk=Le;}
                else if (*p=='<'){
                    ++p;
                    if (*p=='='){
                        ++p;
                        tk=ShlAssign;
                    }
                    else{
                        tk=Shl;
                    }
                }
                else{
                    tk=Lt;
                    return;
                }
        case '>': if (*p=='='){++p;tk=Ge;}
                else if (*p=='>'){
                    ++p;
                    if (*p=='='){
                        ++p;
                        tk=ShrAssign;
                    }
                    else{
                        tk=Shr;
                    }
                }
                else{
                    tk=Gt;
                    return;
                }
        case '|': if (*p=='|') {++p;tk=Lor;}
                else if (*p=='='){++p;tk=OrAssign;}
                else tk=Or;return;
        case '&': if (*p=='&') {++p;tk=Lan;}
                else if (*p=='=') {++p;tk=AndAssign;}
                else tk=And;return;
        case '^':if (*p=='=') {++p;tk=XorAssign;} else tk=Xor;return;
        case '*':if (*p=='=') {++p;tk=MulAssign;} else tk=Mul;return;
        case '%':if (*p=='=') {++p;tk=ModAssign;} 
                else tk=Mod;return;
        case '[': tk=Bracket;return;
        case '?': tk=Cond; return;
        case '.':tk=Dot;return;
        default:return;
        
        }
    }
}

enum {
    PAGE_SIZE = 0x1000, PHDR_NUM = 4, SHDR_NUM = 11,
    DYN_NUM = 15
};


int ef_getidx(char *name){
    int i;
    for(i=0;i<ef_count;i++){
        if (!strcmp(ef_cache[i]->name,name)){
            break;
        }
    }

    if (i==ef_count){
        int dladdr;
        if ((dladdr=(int)dlsym(0,name))){
            
        }
    }
}

void elf32_init(int poolsz){
    int i;
    freebuf=malloc(poolsz);
    char *o=(char*)(((int)freebuf+PAGE_SIZE-1)&-PAGE_SIZE);
    
    plt_func_addr=malloc(sizeof(char*)*PTR);
    for(i=0;i<PTR;++i){
        plt_func_addr[i]=o+i*16;
    }

    
}


int main(int argc,char **argv) {
#if defined(__x86_64__) || defined(__aarch64__)
#define int long
#endif  
    
    int *freed_ast,*ast;//area syntax tree 
    int elf_fd;
    int i;


    printf("argc:%d\n",argc);
    for(int i=0;i<argc;i++){
        printf("argv[%d]:%s\n",i,argv[i]);
    }

    --argc,++argv;
    if (argc>0 && **argv=='-' && (*argv)[1]=='s'){
        src=1;
        // printf("source get\n");
        --argc,++argv;
    }

    if (argc > 0 && **argv=='-' && (*argv)[1]=='o'){
        elf=1;
        if (argc <1 ) die("no output file argument");
        if ((elf_fd=open(*argv,_O_CREAT | _O_WRONLY,0775)) < 0){
            printf("could not open(%s)\n",*argv);
            return -1;
        }
        --argc,++argv;
        
    }

    if (argc<1){
        die("usage: amacc[-s] [-o object] file");
    }

    int fd;
    if ((fd=open(*argv,0))<0){
        printf("could not open(%s)\n",*argv);
        return -1;
    }

    int poolsz=1024*1024;
    if (!(text = le = e = malloc(poolsz))){
        die("could not allocate text area");
    }
    if (!(sym = malloc(poolsz))){
        die("could not allocate symbol area");
    }
    if (!(freedata = _data = data = malloc(poolsz))){
        printf("could not allocate data area");
    }
    if (!(tsize=malloc(PTR*sizeof(int)))){
        die("could not allocate tsize area");
    }
    if (!(members = malloc(PTR * sizeof(struct members_s*)))){
        die("could not malloc() members area");
    }
    if (!(freed_ast = ast = malloc(poolsz))){
        die("could not allocate abstract syntax tree area");
    }
    if (!(ef_cache = malloc(PTR * sizeof(struct ef_s*)))){
        die("could not malloc() external fucntion cache");
    }

    memset(sym, 0,poolsz);
    memset(e, 0 ,poolsz);
    memset(data, 0,poolsz);
    
    
    memset(tsize, 0, PTR*sizeof(int));
    memset(members, 0, PTR*sizeof(struct member_s*));
    memset(ast, 0 , poolsz);
    ast=(int *)((int) ast + poolsz);//abstract syntax tree is most efficiently built as a stack

    /* Register keywords and system calls to symbol stack
     * must match the sequence of enum
     */
    p = "break continue case char default else enum if int return sizeof "
        "struct union switch for while do goto __clear_cache void main";

    for(i=Break;i<=Goto;i++){
        next();
        id->tk=i;
        id->class=Keyword;
    }

    next(); id->class=ClearCache;id->type=INT,id->val=CLCA;
    
    next(); id->tk=Char;id->class=Keyword;
    next();
    struct ident_s *idmain=id;id->class=Main;
    
    
    


    free(freed_ast);
    free(tsize);
    free(freedata);
    free(sym);
    free(text);
    

    return 0;
    

}
