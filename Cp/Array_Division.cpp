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
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define pi (3.141592653589)
#define PI 3.1415926535897932384626433832795

bool check(int mid, int n, int k, vi &a) {
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        
        if (sum + a[i] <= mid) {
            sum += a[i];
        } else {
            cnt++;
            sum = a[i];
            if(a[i] >mid)return false;
        }
    }
    return cnt <= k;
}

int32_t main() {
    ff();
    int n, k;
    cin >> n >> k;
    vi a(n);
    input(0, n, a);

    int l = 0;
    int h =1e18;
    int ans = h;

    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (check(mid, n, k, a)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
    return 0;
}
