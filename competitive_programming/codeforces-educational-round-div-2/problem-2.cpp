#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> extended_sum(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
        extended_sum[i + 1] = extended_sum[i] + a[i % n];
    }
    
    ll count = 0;
    deque<int> dq;
    for (int l = 1, r = 1; l <= n * k; l++) {
        while (r <= min(n * k, l + 2 * n - 1) && extended_sum[r] - extended_sum[l - 1] < x) {
            r++;
        }
        if (r <= n * k) count += (n * k - r + 1);
    }
    
    cout << "count: "<< count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
