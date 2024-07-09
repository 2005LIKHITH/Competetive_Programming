#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int &ai : a) cin >> ai;

    // Sort the initial costs to maximize the number of packs we can buy
    sort(all(a));

    // Prefix sum to calculate the total cost quickly
    vi prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    int total_packs = 0;

    // Use binary search to find the maximum number of days we can buy packs
    for (int i = 0; i < n; ++i) {
        if (prefix[i] > x) break;
        int left = 0, right = (x - prefix[i]) / (i + 1) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[i] + (i + 1) * mid <= x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        total_packs += left * (i + 1);
    }

    cout << total_packs << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
