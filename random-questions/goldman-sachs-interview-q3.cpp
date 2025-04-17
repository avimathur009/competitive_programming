//Trapping rain water with PITS (-ve height)

#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

void solve(vector<int> &height){
    int n=height.size();
    vector<int> nge(n,0), pge(n,0);
    stack<int> stnge, stpge;
    for(int i=n-1;i>=0;i--){
        if(stnge.empty()){
            stnge.push(height[i]);
        }
        else{
            while(!stnge.empty() && stnge.top()<height[i]){
                stnge.pop();
            }
            if(!stnge.empty()){
                nge[i]=stnge.top();
            }
            else{
                stnge.push(height[i]);
            }
        }
        if(stpge.empty()){
            stpge.push(height[n-1-i]);
        }
        else{
            while(!stpge.empty() && stpge.top()<height[n-1-i]){
                stpge.pop();
            }
            if(!stpge.empty()){
                pge[n-1-i]=stpge.top();
            }
            else{
                stpge.push(height[n-1-i]);
            }
        }
    }
    int trappedWater=0;
    for(int i=0;i<n;i++){
        //cout<<"pge: "<<pge[i]<<" | "<<"nge: "<<nge[i]<<endl;
        if(height[i]<min(pge[i],nge[i])){
            trappedWater += min(pge[i],nge[i]) - height[i];
            //cout<<"trappedWater: "<<min(pge[i],nge[i]) - height[i]<<endl;
        }
    }
    cout<<"trappedWater: "<<trappedWater;
}

int main(){
    vector<int> height = {0,1,-2,2,1,0,1,3,2,1,2,1};
    solve(height);
    return 0;
}