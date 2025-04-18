#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

void solve(string s){
    int n = s.size();
    int st=0, end=0, maxLen=0, ans=0;
    while(end<n && st<=end){
        char ch = s[end];
        if(s[st]!=s[end]){
            while(st<=end && s[st]!=s[end]){
                st++;
            }
        }
        if(maxLen<end-st+1){
            ans=st;
            maxLen=end-st+1;
        }
        end++;
    }
    cout<<"maxLen: "<<maxLen<<endl;
    cout<<"starting: "<<ans;
}

int main(){
    string s = "aabbbbccd";
    solve(s);
    return 0;
}