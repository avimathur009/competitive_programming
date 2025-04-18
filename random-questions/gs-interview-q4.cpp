//VARIATION #1 of:
//https://leetcode.com/problems/longest-repeating-character-replacement/description/

//Here instead of any repeating character -> when only repeating 'B' is asked
//SAME goes for -> when only repeating 'A' is asked 

#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

void solve(string s, int k){
    int n = s.size();
    unordered_map<char,int> mp;
    int st=0, end=0, maxLen=0;
    while(end<n && st<=end){
        mp[s[end]]++;
        if(s[end]=='A' && mp['A']>k){
            while(mp['A']>k){
                mp[s[st]]--;
                st++;
            }
        }
        maxLen = max(maxLen,end-st+1);
        end++;
    }
    cout<<"maxLen: "<<maxLen<<endl;
}

int main(){
    string s = "AABABBA";
    int k = 1;
    solve(s,k);
    return 0;
}