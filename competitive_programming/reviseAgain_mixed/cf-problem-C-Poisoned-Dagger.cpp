#include<bits/stdc++.h>
using namespace std;

bool checkIfPossible(long long k, long long n, long long h, vector<long long> &attackTime){
    long long damage = 0;
    for(long long i=0;i<n-1;i++){
        if(attackTime[i]+k>attackTime[i+1]){
            damage += attackTime[i+1]-attackTime[i];
        }
        else{
            damage+=k;
        }
    }
    damage+=k;
    if(damage>=h){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, h;
        cin>>n>>h;
        vector<long long> attackTime(n,0);
        for(long long i=0;i<n;i++){
            cin>>attackTime[i];
        }
        long long low = 0, high = h;
        while(low<=high){
            long long possK = (high+low)/2;
            bool isPossible = checkIfPossible(possK,n,h,attackTime);
            if(isPossible){
                high = possK-1;
            }
            else{
                low=possK+1;
            }
        }
        cout<<low<<endl;
    }
    return 0;
}