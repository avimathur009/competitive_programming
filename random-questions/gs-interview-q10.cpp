#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

void solve(string s1, string s2){
    vector<vector<int>> vis(9,vector<int>(9,0));
    if(s1.compare(s2)==0){
        cout<<0;
        return;
    }
    int stx=s1[1]-'0', sty=s1[3]-'0';
    int endx=s2[1]-'0', endy=s2[3]-'0';
    vector<int> dx={1,-1,1,-1};
    vector<int> dy={1,-1,-1,1};
    queue<vector<int>> q;
    q.push({stx,sty,0});
    vis[stx][sty]=1;
    while(!q.empty()){
        vector<int> pos = q.front();
        int x=pos[0], y=pos[1], moves=pos[2];
        if(x==endx && y==endy){
            cout<<"moves: "<<moves;
            return;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=1 && nx<=8 && ny>=1 && ny<=8 && vis[nx][ny]==0){
                q.push({nx,ny,moves+1});
                vis[nx][ny]=1;
            }
        }
    }
    cout<<-1;
    return;
}

int main(){
    string start="(3,4)";
    string end="(3,7)";
    solve(start,end);
    return 0;
}