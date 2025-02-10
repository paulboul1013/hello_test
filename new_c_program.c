#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void str_read(char str[],int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%c",&str[i]);
        if (str[i]=='\n'){
            break;
        }
    }
    str[i]='\0';
}



int main()
{

    srand(time(0));


    const char *source="test";
    char destination[5];

    strcpy(destination,source);

    printf("%s\n",destination);




    printf("\n");

    return 0;
}