#include <iostream>
#include <vector>


// #include "intcell.h"

using namespace std;





int main(){

    int squares[]={1,2,3,4,5,6,7,8,9,10};
    int sum=0;
    for(int i=0;i<10;i++){
        sum+=squares[i];
    }

    for(int x:squares){
        sum+=x;
    }

    sum=0;
    for(auto x:squares){
        sum+=x;
    }

    


    return 0;
}