#include <bits/stdc++.h>
using namespace std;

int getPosOfCurrCoinSpent(int target, int n, vector<int> &prices){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(prices[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    int n;
    cin>>n;
    vector<int> prices(n,0);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    sort(prices.begin(),prices.end());
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int coinSpent;
        cin>>coinSpent;
        int numShops = getPosOfCurrCoinSpent(coinSpent,n,prices);
        cout<<numShops<<endl;
    }
    return 0;
}