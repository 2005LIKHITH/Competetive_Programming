#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES" << '\n';
#define pno cout << "NO" << '\n';

#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)
#define MOD1 998244353
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int)a.size()

#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nl '\n'
#define sp " "

bool dfs(int i, int j, int n, vector<string>& grid, vector<vector<bool>>& vis, int move) {
    if (i == 1 && j == n - 1) return true;  
    if (i < 0 || i >= 2 || j < 0 || j >= n) return false;  
    if (vis[i][j]) return false;

    vis[i][j] = true;
    bool ans = false;
    if (move == 0) {
      
        ans = dfs(i - 1, j, n, grid, vis, 1) || 
              dfs(i + 1, j, n, grid, vis, 1) ||
              dfs(i, j - 1, n, grid, vis, 1) || 
              dfs(i, j + 1, n, grid, vis, 1);
    } else {
     
        if (grid[i][j] == '>') {
            ans = dfs(i, j + 1, n, grid, vis, 0);
        } else {
            ans = dfs(i, j - 1, n, grid, vis, 0);
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    
    vector<string> grid(2);
    for (int i = 0; i < 2; i++) {
        cin >> grid[i];
    }
    
    vector<vector<bool>> vis(2, vector<bool>(n, false));
    if (dfs(0, 0, n, grid, vis, 0)) {
        pyes
    } else {
        pno
    }
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
