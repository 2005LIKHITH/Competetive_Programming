#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
#define INF 1e18
#define nline "\n"

// Recursive Approach
int dp[200005];
int recur(int n, int m, int k, string s, int i) {
    
    if (i >= n) return 0;
    if (dp[i] != -1) return dp[i];
    if (s[i] == 'C') return INT_MAX;
    if (s[i] == 'W') {
        return dp[i] = 1 + recur(n, m , k, s, i + 1);
   
    }
    int jump = INT_MAX;
    for (int j = 1; j <= m; j++) {
        jump = min(jump, recur(n, m, k, s, i + j));
    }
    return dp[i] = jump;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for(int i=0; i < 200005; i++)dp[i] = -1;
    n++;
    s = "L" + s;

    int ans = recur(n, m, k, s, 0);
    if(ans <= k)pyes
    else pno
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
