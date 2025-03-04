#include <iostream>
#include <cmath>
#include <algorithm>
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

int climbing_stairs(int n){

    if (n==1) return 1;
    if (n==2) return 2;

    return climbing_stairs(n-1)+climbing_stairs(n-2);
}




int climbing_stairs_v2(int n){

    if (n==0) return 0;
    int prev2=0;
    int prev1=1;
    int curr=1;

    for(int i=2;i<=n;i++){
        curr=prev1+prev2;

        prev2=prev1;

        prev1=curr;
    }

    return curr;

}


int tribonacci(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    if (n==2) return 1;
    int prev3=0;
    int prev2=1;
    int prev1=1;
    int curr=prev1;

    for(int i=3;i<=n;i++){
        curr=prev1+prev2+prev1;

        prev3=prev2;
        prev2=prev1;
        prev1=curr;
    }

    return curr;
}

int min(int a,int b){
    if (a<b) return a;
    return b;
}

int mincostclimbstairs(int *cost ,int costsize){
    
    int prev2=0;
    int prev1=0;
    int curr=prev1;

    for(int i=2;i<=costsize;i++){
        curr=min(prev1+cost[i-1],prev2+cost[i-2]);
        prev2=prev1;
        prev1=curr;
    }

    return curr;
}

int max(int a,int b){
    if (a>b)return a;
    return b;
}

int rob(int *nums,int numsize){
    int prev2=0;
    int prev1=nums[0];
    int curr=prev1;
    for(int i=2;i<=numsize;i++){
        curr=max(nums[i-1]+prev2,prev1);

        prev2=prev1;
        prev1=curr;
    }

    return curr;
}

int cmp(const void*a,const void*b){
    return *(const int*)a-*(const int*)b;
}

int deleteeandern_r(int *nums,int nums_size){
    int k=nums_size-1;

    while(nums[k-1]+1==nums[nums_size-1]){ 
        k--;
    }
    return max(nums[nums_size-1]+deleteeandern_r(nums,k),deleteeandern_r(nums,nums_size-1));
}

int deleteandearn(int *num,int nums_size){
    qsort(num,nums_size,sizeof(int),cmp);
}


int main() {
    // Write C++ code here
    // checkPowersOfThree_v3(12) ? cout<<"true":cout<<"false"<<endl;


    cout<<tribonacci(40)<<endl;


    return 0;

}