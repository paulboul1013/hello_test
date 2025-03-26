#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

int computexor_v1(int n){
    int res=0;
    for(int i=1;i<=n;i++){
        res=res^i;
    }
    return res;
}

int computexor(int n){
    if (n%4==0){
        return n;
    }
    if (n%4==1){
        return 1;
    }
    if (n%4==2){
        return n+1;
    }
    else{
        return 0;
    }
}

int countvalues(int n){
    int unset_bits=0;
    while (n){
        if ((n&1)==0){
            unset_bits++;
        }
        n=n>>1;
    }

    return 1<<unset_bits;
}

bool ispoweroftwo(int x){
    return x&& (!(x&(x-1)));
}

int findxor(int set[],int n){
    if (n==1){
        return set[0];
    }
    else{
        return 0;
    }
}

int setbitnumber(int n){
    n|=n>>1;
    n|=n>>2;
    n|=n>>4;
    n|=n>>8;
    n|=n>>16;

    n=n+1;
    return (n>>1);
}

int setbitnumber_v2(int n){
    if (n==0){
        return 0;
    }

    int msb=0;
    n=n/2;
    while (n!=0){
        n=n/2;
        msb++;
    }
    return (1<<msb);
}

int setbitnumber_v3(int n){
    int k=__builtin_clz(n);
    
    return 1<<(31-k);
}

static bool allbitsareset(int n){
    if (((n+1)&n)==0){
        return true;
    }
    else{
        return false;
    }
}

bool bitsareinaltorder(unsigned int n){

    unsigned int num=n^(n>>1);
    return allbitsareset(num);

}

void set(int &num,int pos)
{
    num|=(1<<pos);
}

void unset(int &num,int pos){
    num&=(~(1<<pos));
}
void toggle(int &num,int pos){
    num^=(1<<pos);
}

bool at_position(int num,int pos){
    bool bit=num&(1<<pos);
    return bit;
}

void strip_last_set_bit(int &num){
    num=num&(num-1);
}

int lowest_set_bit(int num){
    int ret=num&(-num);
    return ret;
}

string getbinaryrep(int n){
    string ans="";

    for(int i=31;i>=0;i--){
        if (n&(1<<i)){
            ans+='1';
        }
        else{
            ans+='0';
        }
    }
    return ans;
}

string getbinaryrep_v2(int n){
    string ans="";
    for(int i=0;i<32;i++){
        ans+='0';
    }

    for(int i=0;i<32;i++){
        if (n%2==1){
            ans[31-i]='1';
        }
        n/=2;
    }
}

int gcd(int a,int b){
    if (a==b){
        return b;
    }
    return (a>b)? gcd(a-b,b):gcd(a,b-a);
}

int gcd_v2(int a,int b){
    if (a==0){
        return b;
    }
    return gcd_v2(b%a,a);
}

int gcd_v3(int a,int b){
    if (b==0||a==b){
        return a;
    }
    if (a==0){
        return b;
    }

    if ((a&1)==0&&(b&1)==0){
        return gcd_v3(a>>1,b>>1)<<1;
    }

    if ((a&1)==0&&(b&1)==1){
        return gcd_v3(a>>1,b);
    }

    if ((a&1)==1&&(b&1)==0){
        return gcd_v3(a,b>>1);
    }

    return (a>b) ? gcd_v3(a-b,b):gcd(a,b-a);
    
}

bool detect_two_have_opposite_signs(int x,int y){
    bool f=((x^y)<0);
    return f;
}

int abs_my(int a){
    unsigned int r;
    int const mask=a>>sizeof(int)*32-1;
    
    r=(a+mask)^mask;
    return r;
}

int min_my(int x,int y){
    return y^((x^y)&-(x<y));
}



int main(){

  

    
    return 0;

}