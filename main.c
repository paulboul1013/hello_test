#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int add(int x,int y){
    return x+y;
}

double fun2(int n){
    int i;
    double k;
    double sum=0;
    for (i=1;i<=n;i+=2){
        k=(double) 1/i;
        sum+=k;
    }

    return sum;
}

double fun1(int n){
    int i;
    double k;
    double sum=0;
    for (i=2;i<=n;i+=2){
        k=(double) 1/i;
        sum+=k;
    }

    return sum;
}

int main(){

    
    int a=100;
    int *p1=&a;
    int **p2=&p1;

    printf("%x",&a);
    printf("%x",*p2);

    
    return 0;
}

