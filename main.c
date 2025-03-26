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


void die(char *msg){
    printf("%s\n",msg);
    exit(1);
}




int main(int argc,char **argv) {
#if defined(__x86_64__) || defined(__aarch64__)
#define int long
#endif  
    
    int *freed_ast,*ast;//area syntax tree 
    int elf_fd;


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


    free(freed_ast);
    free(tsize);
    free(freedata);
    free(sym);
    free(text);
    

    return 0;
    

}
