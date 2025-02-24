#include <iostream>
#include <vector>

using namespace std;


vector<int> productexceptself(vector<int>&arr){
    int n=arr.size();

    vector<int> res(n,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i!=j){
                res[i]*=arr[j];
            }
        }
    }

    return res;
}

vector<int> productexceptself_2(vector<int> &arr){
    int n=arr.size();

    vector<int> preproduct(n),suffproduct(n),res(n);

    preproduct[0]=1;

    for(int i=1;i<n;i++){
        preproduct[i]=arr[i-1]*preproduct[i-1];
    }

    
}

int main(){
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productexceptself(arr);
    for (int val : res) 
        cout << val << " ";
    return 0;
}