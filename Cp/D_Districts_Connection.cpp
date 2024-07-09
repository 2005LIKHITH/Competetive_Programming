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

void solve() {
    int n;
    cin >> n;
    map<int, vi> mp;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        mp[t].push_back(i);
    }
    if (mp.size() == 1) {
        pno
        return;
    }
    pyes
    cout << endl;

    vector<vector<int>> grid;
    for (auto &it : mp) {
        grid.push_back(it.second);
    }


    for (int i = 1; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[0][0] << " " << grid[i][j] << endl;
        }
    }

    for (int i = 1; i < grid[0].size(); i++) {
        cout << grid[0][i] << " " << grid[1][0] << endl;
    }
}

int32_t main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
        cout << endl;
    }
}
