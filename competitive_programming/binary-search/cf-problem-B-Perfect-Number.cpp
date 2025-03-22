#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

int main(){
    int k;
    cin>>k;
    ll ul = pow(10,9);
    int temp = 1;
    for(ll i=0;i<=ul;i++){
        ll num = i;
        int sum=0;
        while(num>0){
            sum+=num%10;
            num=num/10;
        }
        if(sum==10){
            if(temp==k){
                cout<<i<<endl;
                break;
            }
            else{
                temp++;
            }
        }
    }
    return 0;
}