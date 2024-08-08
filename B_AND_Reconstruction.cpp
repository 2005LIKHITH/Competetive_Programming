#include <bits/stdc++.h>
using namespace std;

// New Method
#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define nl '\n'
#define sp " "

void solve() {
    int n;
    cin >> n;
    vi b(n-1);
    for (int i = 0; i < n-1; ++i) cin >> b[i];
    
    vector<vector<int>> bit(n, vector<int>(30, 0));
    
    for (int i = 29; i >= 0; --i) {
        if (b[0] & (1 << i)) {
            bit[0][i] = 1;
            bit[1][i] = 1;
        }
    }

    for (int i = 1; i < n-1; ++i) {
        for (int j = 29; j >= 0; --j) {
            if (b[i] & (1 << j)) {
                if (bit[i][j] == -1) {
                    cout << -1 << nl;
                    return;
                }

                bit[i][j] = 1;
                bit[i+1][j] = 1;
            }
        }
        for (int j = 29; j >= 0; --j) {
            if (bit[i][j] == 1 && bit[i+1][j] != 1) {
                bit[i+1][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 29; j >= 0; --j) {
            if (bit[i][j] == 1) {
                ans |= (1 << j);
            }
        }
        cout << ans << sp;
    }
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
