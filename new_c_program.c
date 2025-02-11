#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int,int);
int multiply(int,int);
int cal(int (*)(int,int));
int main()
{

    



    return 0;
}

int add(int a,int b){
    return a+b;
}

int multiply(int a,int b){
    return a*b;
}

int cal(int (*op)(int,int)){
    int result=1;
    for(int i=1;i<=5;i++){
        result=op(result,i);
    }
    return result;
}