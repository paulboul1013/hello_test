#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>

void die(char *msg){
    printf("%s\n",msg);
    exit(1);
}

int src;//print source
int elf;//print ELF(The Executable and Linkable Format) format

int main(int argc,char **argv) {
#if defined(__x86_64__) || defined(__aarch64__)
#define int long
#endif  
    
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

    return 0;
    

}
