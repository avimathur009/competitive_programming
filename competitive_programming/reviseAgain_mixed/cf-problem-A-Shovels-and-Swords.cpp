#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int a, b;
        cin>>a>>b;
        int minVal = min(a,min(b,(a+b)/3));
        cout<<minVal<<endl;
    }
    return 0;
}

//f(a,b) -> max emeralds earned by monocarp

//f(a,b) = max(1+f(a-2,b-1)   ,   1+f(a-1,b-2));