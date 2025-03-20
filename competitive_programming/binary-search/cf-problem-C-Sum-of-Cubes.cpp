#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    map<long long int,int> mp;
    for(long long int i=1; i*i*i<=pow(10,12); i++){
        mp[i*i*i]=1;
    }
    while(t--){
        long long int x;
        cin>>x;
        bool found=false;
        for(long long int i=1;i<=pow(10,4);i++){
            long long int acube = i*i*i;
            if(mp.count(x-acube)!=0){
                cout<<"YES"<<endl;
                found=true;
                break;
            }
        }
        if(!found){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}