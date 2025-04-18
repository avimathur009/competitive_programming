//Q: Given a 2D grid, each cell has a item which has value >=0, 
//we are standing at bottom left cell of the grid and 
//need to reach top right cell.
//So we need to reach from r-1,0 to 0,c-1 with maxValue.

#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

void solve(vector<vector<int>> &grid){
    int n = grid.size(), m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][m-1]=grid[0][m-1];
    for(int i=1;i<n;i++){
        dp[i][m-1]=dp[i-1][m-1]+grid[i][m-1];
    }
    for(int j=m-2;j>=0;j--){
        dp[0][j]=dp[0][j+1]+grid[0][j];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=m-2;j>=0;j--){
            dp[i][j]=grid[i][j]+max(dp[i-1][j],dp[i][j+1]);
        }
    }
    cout<<"ans: "<<dp[n-1][0];
}

int main(){
    vector<vector<int>> grid = {{0,0,5},
                                {0,1,0},
                                {2,0,1}};
    solve(grid);
    return 0;
}