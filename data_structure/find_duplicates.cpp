#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;


vector<int> find_duplicates(vector<int> &arr){
    int n=arr.size();
    unordered_map<int,int> freqmap;
    vector<int> result;

    for(int i=0;i<n;i++){
        freqmap[arr[i]]++;
    }

    for(auto &entry:freqmap){
        if (entry.second>1){
            result.push_back(entry.first);
        }
    }

    if (result.empty()){
        result.push_back(-1);
    }

    return result;
}

vector<int> find_duplicates_2(vector<int>&arr){
    int n=arr.size();
    vector<int> freqarr(n);
    vector<int> result;

    for(int i=0;i<n;i++){
        freqarr[arr[i]]++;
    }

    for (int i=0;i<n;i++){
        if (freqarr[i]>1){
            result.push_back(i);
        }
    }

    if (result.empty()){
        result.push_back(-1);
    }

    return result;

}

int main(){
    vector<int> arr={1, 6, 5, 2, 3, 3, 2};

    vector<int> duplicates=find_duplicates_2(arr);

    for (int element:duplicates){
        cout<<element<<" ";
    }

    return 0;
}