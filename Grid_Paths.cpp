#include <bits/stdc++.h>
using namespace std;

// Speed up input/output operations
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define int long long int
#define MOD (int)(1e9 + 7)
#define nl '\n'

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n));


    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin>>grid[i][j];
          
        }
    }
    // vector<vector<int>>a(n,vector<int>(n,1));

    dp[0][0] = 1;
    if(grid[0][0] == '*'){
        cout<<"0"<<nl;
        return;
    }
    if(grid[n-1][n-1] == '*'){
        cout<<"0"<<nl;
        return;
    }
    //state dp[i][j] = the no of ways to reach i,j from 0
    //transition dp[i][j] = dp[i-1][j]+dp[i][j-1]
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(i == 0 && j == 0)continue;
            if(grid[i][j] == '*')continue;
            else{
                int ans1 = i > 0 ? dp[i-1][j]: 0;
                int ans2 = j > 0 ? dp[i][j-1]:0;
                dp[i][j] = (ans1+ans2)%MOD;
            }

        }
    }
    cout<<dp[n-1][n-1]<<endl;
}

int32_t main() {
    ff();
    int tc;
    tc = 1;
    while(tc--) {
        solve();
        cout << nl;
    }
}
