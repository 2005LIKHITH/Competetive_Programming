#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define vi vector<int>
#define pyes cout << "YES" << '\n';
#define pno cout << "NO" << '\n';
#define sz(a) (int)a.size()

void solve() {
    int a, b;
    cin >> a >> b;
    int tot = a + 2 * b;
    if (tot % 2 != 0) {
        pno
        return;
    }
    int half = tot / 2;
    for (int i = 0; i <= b; i++) {
        int sum_twos = 2 * i;
        int sum_ones = half - sum_twos;
        if (sum_ones >= 0 && sum_ones <= a) {
            pyes
            return;
        }
    }
    pno
}


signed main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
