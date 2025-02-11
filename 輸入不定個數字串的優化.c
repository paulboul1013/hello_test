#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{


    char *str[100];
    char raw[5000];
    char input[50];
    int len=0;
    int size=0;
    while(1){
        scanf("%s",input);
        if (strcmp(input,"end")==0) break;
        str[len]=raw+size;
        strcpy(str[len],input);
        size+=strlen(input)+1;
        len++;
    }

    
    printf("\n");


    for(int i=0;i<len;i++){
        printf("%s ",str[i]);
    }


    printf("\n(%d %d)\n",len,size);

    printf("\n");

    return 0;
}