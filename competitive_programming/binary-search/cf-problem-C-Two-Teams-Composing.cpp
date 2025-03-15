#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        int maxFreq=INT_MIN;
        map<int,int> mpFreq;
        for(int i=0;i<n;i++){
            int currSkill;
            cin>>currSkill;
            mpFreq[currSkill]++;
            maxFreq=max(maxFreq,mpFreq[currSkill]);
        }
        int diff = mpFreq.size();
        int ans = max(min(diff,maxFreq-1),min(diff-1,maxFreq));
        cout<<ans<<endl;
    }
    return 0;
}