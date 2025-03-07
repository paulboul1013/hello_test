// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


bool isPrime(int num) {
    if (num <= 1) return false;  // 1和負數不是質數
    if (num == 2) return true;   // 2是質數
    if (num % 2 == 0) return false;  // 偶數（除了2）不是質數
    
    // 只檢查到平方根，並只檢查奇數
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// 找出範圍內質數的主函數
vector<int> findPrimes(int left, int right) {

    vector<int> save_prime;

    
    for (int i = left; i <= right; i++) {
        if (isPrime(i)) {
            save_prime.push_back(i);
        }
    }
    return save_prime;
}

vector<int> closestPrimes(int left, int right) {
    vector<int> save_prime;
    vector<int> ans(2);

    save_prime=findPrimes(left,right);


    if (save_prime.size()==1){
        ans[0]=-1;
        ans[1]=-1;
        return ans;
    }



    int min=INT_MAX;
   

    for(int i=0;i<save_prime.size()-1;i++){
        for(int j=i+1;j<save_prime.size();j++){
            if (save_prime[j]-save_prime[i]==min){
                    continue;
            }
            if(save_prime[j]-save_prime[i]<min){
                ans[0]=save_prime[i];
                ans[1]=save_prime[j];
                min=save_prime[j]-save_prime[i];
            }
        
        }
    }

    return ans;

}



vector<int> sieve (int upperlitmit){
    vector<int> si(upperlitmit+1,1);

    si[0]=0;
    si[1]=0;

    for(int number=2;number*number<=upperlitmit;number++){
        if (si[number]==1){
            for(int multiple=number*number; multiple<=upperlitmit; multiple+=number){
                si[multiple]=0;
            }
        }
    }

    return si;
}

vector<int> closestPrimes_v2(int left, int right) {


    int upperlimit=right;

    vector<int> sievearray=sieve(upperlimit);

    vector<int>  primenumbers;

    for(int num=left;num<=right;num++){
        if (sievearray[num]==1){
            primenumbers.push_back(num);
        }
    }    

    if (primenumbers.size()<2){
        return vector<int>{-1,-1};
    }
    
    int min=INT_MAX;
    vector<int> closet_pair(2,-1);

    for(int index=1;index<primenumbers.size();index++){
        int diff=primenumbers[index]-primenumbers[index-1];
        if (diff<min){
            min=diff;
            closet_pair[0]=primenumbers[index-1];
            closet_pair[1]=primenumbers[index];

        }
    }

    return closet_pair;

}


void seiveoferatosthenes(int n){
    vector<bool> prime(n+1,true);

    for (int p=2;p*p<=n;p++){
        if (prime[p]==true){
            for (int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }

    for(int p=2;p<=n;p++){
        if (prime[p]){
            cout<<p<<" ";
        }
    }

    
}


int main() {
    // Write C++ code here

    
    seiveoferatosthenes(90000);

    return 0;
}