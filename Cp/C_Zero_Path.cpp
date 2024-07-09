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
#define priority_queue<pii, vector<pii>, greater<pii>> minpq;
#define priority_queue<pii> maxpq;
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define  ppc   __builtin_popcount
#define  ppcll   __builtin_popcountll
#define pi (3.141592653589)
#define PI 3.1415926535897932384626433832795

bool solve1(int n,int m,vector<vector<int>>&grid,int row,int col,int sum,vector<vector<vector<int>>>&dp){
    if(dp[row][col][sum] != -1)return dp[row][col][sum];
    if(row == 0 && col == 0){
        return dp[row][col][sum] = sum+grid[row][col] == 0;
    }
    if(row < 0 || col < 0)return false;
    return dp[row][col][sum] = (solve1(n,m,grid,row-1,col,sum+grid[row][col],dp) || solve1(n,m,grid,row,col-1,sum+grid[row][col],dp));
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin>>grid[i][j];
        }
    }
    //we will start from from (n,m) and go to (0,0);
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>((n+1)*(m+1),-1)));
    bool ans = solve1(n,m,grid,n-1,m-1,0,dp);
    if(ans)pyes
    else pno
}

int32_t main(){
    ff();
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}