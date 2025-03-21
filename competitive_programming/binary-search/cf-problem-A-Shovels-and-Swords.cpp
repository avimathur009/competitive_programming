//**THIS GIVE TLE (RUN TIME ERROR ON CF) -> NO DP Possible**

#include<bits/stdc++.h>
using namespace std;

int getMax(int a, int b, vector<vector<int>> &dp){
    if(a<=0 || b<=0){
        return 0;
    }
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    int way1=0, way2=0;
    if(a-1>=0 && b-2>=0){
        way1 = 1 + getMax(a-1,b-2,dp);
    } 
    if(a-2>=0 && b-1>=0){
        way2 = 1 + getMax(a-2,b-1,dp);
    }
    return dp[a][b]=max(way1,way2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        if(a==0 || b==0){
            cout<<0<<endl;
            continue;
        }
        vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
        cout<<getMax(a,b,dp)<<endl;
    }
    return 0;
}

//f(a,b) -> max emeralds earned by monocarp

//f(a,b) = max(1+f(a-2,b-1)   ,   1+f(a-1,b-2));