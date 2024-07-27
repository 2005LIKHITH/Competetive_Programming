#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> grid(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    int reduced_size = n / k;
    vector<string> reduced_grid(reduced_size, string(reduced_size, '0'));
    
    for (int i = 0; i < n; i += k) {
        for (int j = 0; j < n; j += k) {
            reduced_grid[i / k][j / k] = grid[i][j];
        }
    }
    
    for (const auto& row : reduced_grid) {
        cout << row << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
