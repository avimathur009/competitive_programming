#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

bool cmp(map<string,int>::iterator it1, map<string,int>::iterator it2){
    return it1->second>it2->second;
}

string getIpKey(string ip){
    string ipKey="";
    int n = ip.size();
    int i=0;
    while(i<n && ip[i]!=" "){
        ipKey=ipKey+ipKey[i];
        i++;
    }
    return ipKey;
}

vector<string> solve(int n, vector<string> &ips){
    map<string,int> ipKeyToCount;
    int maxFreq=0;
    for(int i=0;i<n;i++){
        string ip = ips[i];
        string ipKey = getIpKey(ip);
        if(ipKeyToCount.count(ipKey)!=0){
            ipKeyToCount[ipKey]++;
        }
        else{
            ipKeyToCount[ipKey]=1;
        }
        maxFreq=max(maxFreq,ipKeyToCount[ipKey]);
    }
    sort(ipKeyToCount.begin(),ipKeyToCount.end(),cmp);
    vector<string> ans;
    map<string,int>::iterator it=ipKeyToCount.begin();
    while(it->second==maxFreq && it!=ipKeyToCount.end()){
        ans.push_back(it->first);
        it++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> ips;
    for(int i=0;i<n;i++){
        cin>>ips[i];
    }
    vector<string> ans = solve(n,ips);
    cout<<"answer is: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}