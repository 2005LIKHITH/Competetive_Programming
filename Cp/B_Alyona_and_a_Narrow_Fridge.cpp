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

int check(int mid, vi &a , int maxi) {

    int cnt = 0;
    for (int i = 0; i < mid; i += 2) {
        cnt += a[i];
    }
    return cnt <= maxi;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n, 0);
    input(0, n, a);
    // sort(all(a));

    int l = 1;
    int h = n;
    int ans = -1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        vi  b(a.begin(), a.begin() + mid);
        sort(all(b), greater<int>());
        if (check(mid, b, k)) {
            ans = mid;
            l = mid + 1;
        } else h = mid - 1;
    }
    cout << ans << endl;
}

int32_t main() {

    solve();
    // cout<<endl;
}