#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool twosum(vector<int>&arr,int target){
    int n=arr.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i]+arr[j]==target){
                return true;
            }
        }
    }
}

bool binarysearch(vector<int> &arr,int left,int right,int target){
    while(left<=right){
        int mid=left+(right-left)/2;
        if (arr[mid]==target){
            return true;
        }
        if (arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return false;
}

bool two_sum_2(vector<int> &arr,int target){
    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
        int complement=target-arr[i];

        if (binarysearch(arr,i+1,arr.size()-1,complement)){
            return true;
        }
    }

    return false;
}

bool two_sum_3(vector<int> &arr,int target){
    sort(arr.begin(),arr.end());

    int left=0,right=arr.size()-1;

    while(left<right){
        int sum=arr[left]+arr[right];

        if (sum==target){
            return true;
        }
        else if (sum<target){
            left++;
        }else{
            right--;
        }
        
    }

    return false;
}

bool two_sum_4(vector<int> &arr,int target){
    unordered_set<int> s;
    
    for(int i=0;i<arr.size();i++){
        int complement=target-arr[i];
        
        if (s.find(complement)!=s.end()){
            return true;
        }

        s.insert(arr[i]);
    }

    return false;

}

int main(){
    vector<int> arr={0,-1,2,-3,1};
    int target=-2;

    if (two_sum_4(arr,target)){
        cout<<"true"<<endl;
    }

    else{
        cout<<"false"<<endl;
    }
}