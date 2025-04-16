#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long int ll;

void solve(){
    string n;
    cin>>n;
    if(n.size()==1){
        cout<<0<<endl;
        return;
    }
    ll numZero=0, numNonZero=0;
    for(ll i=0;i<n.size();i++){
        if(n[i]=='0'){
            numZero++;
        }
        else{
            numNonZero++;
        }
    }
    ll count=0;
    bool crossed=false;
    for(ll i=0;i<n.size();i++){
        if(n[i]=='0'){
            if(numNonZero==1 && crossed==true){
                count++;
            }
        }
        else{
            if(numNonZero>1){
                count++;
                numNonZero--;
            }
            else{
                crossed=true;
            }
        }
    }
    cout<<count<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}