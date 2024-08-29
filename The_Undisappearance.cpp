#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> pq(a.begin(), a.end());

    while (k > 0) {
        int t = pq.top();
        pq.pop();
        t << 1;  // t *= 2 using bit manipulation
        pq.push(t);
        k--;
    }

    int sum = 0;
    while (!pq.empty()) {
        sum = (sum + pq.top()) % MOD;
        pq.pop();
    }

    cout << sum << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
