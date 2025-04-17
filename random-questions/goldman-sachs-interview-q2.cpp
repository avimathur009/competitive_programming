#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

bool cmp(vector<int> vec1, vector<int> vec2){
    return vec1[0]<vec2[0];
}

void solve(vector<vector<int>> &input){
    sort(input.begin(),input.end(),cmp);
    for(int i=0;i<input.size();i++){
        vector<int> temp = input[i];
        cout<<"("<<temp[0]<<","<<temp[1]<<")";
    }
    return;
}

int main(){
    vector<vector<int>> input = {{5,7},{15,29},{7,9},{1,5},{12,15},{29,34},{9,12}};
    solve(input);
    return 0;
}