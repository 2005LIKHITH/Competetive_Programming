#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define
#define int long long int
#define vi vector<int>
#define nl '\n'

bool check(int mid, vector<pair<int, int>>& seg, vi& queries, int n, int k) {
    vector<int> a(n, 0);
    for (int i = 0; i < mid; i++) {
        a[queries[i]] = 1;
    }
    
    vector<int> pre(n, 0);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    for (auto &it : seg) {
        int f = it.first;
        int s = it.second;

        int val = pre[s] - (f > 0 ? pre[f - 1] : 0);
        int len = s - f + 1;
        if (val > len / 2) return true;
    }
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> segments(k);
    for (int i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        segments[i] = {p, q};
    }

    int q;
    cin >> q;
    vi queries(q);
    for (auto &it : queries) {
        cin >> it;
        it--;
    }

    int l = 1, h = q, ans = -1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (check(mid, segments, queries, n, k)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << nl;
}

int32_t main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
