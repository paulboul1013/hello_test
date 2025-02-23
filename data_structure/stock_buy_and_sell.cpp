#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxprofit(vector<int>&prices){
    int n=prices.size();
    int res=0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            res=max(res,prices[j]-prices[i]);
        }
    }
    return res;
}
int maxprofit_2(vector<int>&prices){

    int minsorfar=prices[0],res=0;

    for(int i=1;i<prices.size();i++){
        minsorfar=min(minsorfar,prices[i]);

        res=max(res,prices[i]-minsorfar);
    }

    return res;

}

int main(){
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout<<maxprofit_2(prices)<<endl;
    return 0;
}