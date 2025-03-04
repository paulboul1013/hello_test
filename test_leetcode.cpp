#include <iostream>
#include <cmath>
using namespace std;



bool checkPowersOfThree_v2(int n) {
        
    int power=0;

    while (pow(3,power)<=n){
         power++;
    }

    while(n>0){
     if (n>=pow(3,power)){
         n-=pow(3,power);
     }
     if (n>=pow(3,power)){
         return false;
     }

     power--;
    }

    return true;

}

bool checkPowersOfThree_v3(int n) {

    while (n>0){
        if (n%3==2){
            return false;
        }

        n/=3;
       }

       return true;

}



int main() {
    // Write C++ code here
    checkPowersOfThree_v3(12) ? cout<<"true":cout<<"false"<<endl;

    return 0;
}