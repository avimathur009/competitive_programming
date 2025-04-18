//VARIATION #2 of:
//https://leetcode.com/problems/longest-repeating-character-replacement/description/

//Here instead of any repeating character -> when repeating character is specified 'A'
//or 'B' or anything else
//SAME goes for -> when only repeating 'A' is asked 

#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

int getMaxMfe(unordered_map<char,int> mp){
    int mfe=0;
    unordered_map<char,int>::iterator it = mp.begin();
    while(it!=mp.end()){
        if(it->first == 'A' || it->first == 'B'){
            mfe=max(mfe,it->second);
        }
        //mfe=max(mfe,it->second);
        it++;
    }
    return mfe;
}

void solve(string s, int k){
    int n = s.size();
    //diff chars -> (end-st+1)-mfe
    unordered_map<char,int> mp;
    int st=0, end=0, maxLen = 0, mfe = 0;
    while(end<n && st<=end){
        mp[s[end]]++;
        if(s[end] == 'A' || s[end] == 'B'){
            mfe=max(mfe,mp[s[end]]);
        }
        //mfe=max(mfe,mp[s[end]]);
        if(end-st+1-mfe>k){
            while(end-st+1-mfe>k){
                mp[s[st]]--;
                st++;
                mfe = getMaxMfe(mp);
            }
        }
        maxLen=max(maxLen,end-st+1);
        end++;
    }
    cout<<"maxLen: "<<maxLen<<endl;
}

int main(){
    string s = "AABCCCCABBA";
    int k = 1;
    solve(s,k);
    return 0;
}