#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define
#define int long long int
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define nl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    input(0, n, a);
    vi pre(n, 0);

    // Calculate prefix peaks count
    for (int i = 1; i < n - 1; i++) {
        pre[i] = pre[i - 1];
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            pre[i]++;
        }
    }

    int max_peaks = 0;
    int best_l = 0;

    // Sliding window over possible segments
    for (int i = 0; i <= n - k; i++) {
        int current_peaks = pre[i + k - 2] - pre[i];  // Calculate number of peaks in current segment
        if (current_peaks > max_peaks) {
            max_peaks = current_peaks;
            best_l = i;
        }
    }

    cout << max_peaks + 1 << " " << best_l + 1 << nl; 
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
