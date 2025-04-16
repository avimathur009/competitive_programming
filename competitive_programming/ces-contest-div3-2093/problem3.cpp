#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

bool isPrime(long long n) {
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(long long i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

void solve(){
    long long x;
    int k;
    cin >> x >> k;
    if(k == 1)
        cout << (isPrime(x) ? "YES" : "NO") << "\n";
    else {
        if(x == 1)
            cout << (k == 2 ? "YES" : "NO") << "\n";
        else
            cout << "NO" << "\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}