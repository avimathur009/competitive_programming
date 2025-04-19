#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

void solve(string s, int k){
    int n=s.size();
    if(k==n){
        cout<<"ans: "<<1;
        return;
    }
    if(k>n){
        cout<<"ans: "<<0;
        return;
    }
    int st=0, end=k-1;
    unordered_map<string,int> mp;
    int ans=0;
    while(end<n && st<=end){
        string sub = s.substr(st,end-st+1);
        if(mp.count(sub)==0){
            ans++;
            mp[sub]++;
        }
        end++;
        st++;
    }
    cout<<"ans: "<<ans;
}

int main(){
    string s = "aabbbccddddbbabcaabcde";
    int k = 3;
    solve(s,k);
    return 0;
}