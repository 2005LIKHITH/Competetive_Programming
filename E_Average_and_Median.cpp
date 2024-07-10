// very Important binary Search + Dp


#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define mod (int)(1e9 + 7)
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define  ppc         __builtin_popcount
#define  ppcll       __builtin_popcountll
#define pi (3.141592653589)

bool canAchieveAverage(const vector<long double>& a, double avg, int n) {
    vector<double> dp(n, 0);
    dp[0] = a[0] - avg;
    dp[1] = max(a[1] - avg, dp[0] + a[1] - avg);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1] + a[i] - avg, dp[i - 2] + a[i] - avg);
    }
    return max(dp[n - 1], dp[n - 2]) >= 0;
}

int32_t main() {
    int n;
    cin >> n;
    vector<long double> a(n);
    input(0, n, a);

    long double precision = 1e-10;
    long double l = 0, h = 1e18, ans = 0;
    int cnt = 0;

    while (h - l > precision) {
        long double mid = (l + h) / 2;
        if (canAchieveAverage(a, mid, n)) {
            ans = mid;
            l = mid;
        } else {
            h = mid;
        }
        cnt++;
        if (cnt > 500) break;
    }

    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}
