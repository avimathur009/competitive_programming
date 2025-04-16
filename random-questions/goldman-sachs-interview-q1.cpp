#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

void solve(vector<vector<string>> &input){
    unordered_map<string,pair<double,double>> mp;
    double maxAvg=0.0;
    for(int i=0;i<input.size();i++){
        string name = input[i][0];
        double grade = stoi(input[i][1]);
        if(mp.count(name)==0){
            pair<double,double> p = {1.0,grade};
            mp[name]=p;
        }
        else{
            pair<double,double> p = mp[name];
            double freq= p.first;
            double avg=p.second;
            avg=avg*freq;
            avg=(avg+grade);
            freq=freq+1.0;
            avg=avg/freq;
            mp[name]={freq+1,avg};
        }
    }
    unordered_map<string,pair<double,double>>::iterator it = mp.begin();
    while(it!=mp.end()){
        maxAvg=max(maxAvg,(it->second).second);
        it++;
    }
    cout<<maxAvg;
}

int main(){
    //input array is gonna be in thi form
    vector<vector<string>> input = {{"Raechel","100"},{"Phoebe","80"},
                                    {"Monica","95"},{"Raechel","50"},
                                    {"Phoebe","60"}};
    solve(input);
    return 0;
}

TC: O(N+N)
SC: O(N+N+N)