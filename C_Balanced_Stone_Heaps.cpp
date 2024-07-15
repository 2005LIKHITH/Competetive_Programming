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
#define pi (3.141592653589)
#define INF 1e18
#define nline "\n"

// lot to learn from this question in check function
bool check(int x, vi &a) {
    /*
        0 1 2 3 4 5
        [1 2 3 4 5 6]

        lets move from 2 to 6

        when we do forward traversal that means 2 to n you can't set the maximum possible value like you don't know how much to 
        transfer so that we can get maximum advantage
    */
    vector<int> b(a.size(), 0);
    for (int i = a.size() - 1; i >= 2; i--) {
        if (a[i] + b[i] - x < 0) return false;
        int d = min(a[i], b[i] + a[i] - x);//ham utna hi move kar sakthe hain jithna original heap me hai
        b[i - 1] += (d / 3);
        b[i - 2] += 2 * (d / 3);
    }
    if (a[0] + b[0] >= x && b[1] + a[1] >= x) return true;
    return false;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    input(0, n, a);
    int l = 0; // *min_element(all(a)) can be replaced with 0 for lower bound
    int h = *max_element(all(a));
    int ans = -1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (check(mid, a)) l = mid + 1, ans = mid;
        else h = mid - 1;
    }
    cout << ans;
}

int32_t main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
        cout << nline;
    }
    return 0;
}
