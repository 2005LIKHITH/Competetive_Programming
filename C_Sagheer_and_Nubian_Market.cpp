#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define
#define int long long int
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)
#define MOD1 998244353
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }

int check(int k, vi &a, int S, int n) {
    vi temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = a[i] + (i + 1) * k;
    }
    sort(all(temp));
    int totalCost = 0;
    for (int i = 0; i < k; i++) {
        totalCost += temp[i];
        if (totalCost > S) return -1;
    }
    return totalCost;
}

void solve() {
    int n, S;
    cin >> n >> S;
    vi a(n);
    input(0, n, a);

    int l = 0, h = n;
    pair<int, int> ans = {0, 0};

    while (l <= h) {
        int mid = (l + h) / 2;
        int totalCost = check(mid, a, S, n);
        if (totalCost != -1) {
            ans = {mid, totalCost};
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    cout << ans.first << " " << ans.second << endl;
}

int32_t main() {
    ff();
    int tc;
    tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}
