#include<bits/stdc++.h>
using namespace std;

bool checkIfPossible(int k, int n, int h, vector<int> &attackTime){
    int damage = 0;
    for(int i=0;i<n-1;i++){
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
        int n, h;
        cin>>n>>h;
        vector<int> attackTime(n,0);
        for(int i=0;i<n;i++){
            cin>>attackTime[i];
        }
        int low = 0, high = h;
        while(low<=high){
            int possK = (high+low)/2;
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