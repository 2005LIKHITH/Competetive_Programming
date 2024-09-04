#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> result(n + 1, 0);
    string s;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cin >> s;

    vector<bool> visited(n + 1, false);


    auto dfs = [&](int start) {
        vector<int> cycle;
        int current = start;
        
        while (!visited[current]) {
            visited[current] = true;
            cycle.push_back(current);
            current = p[current];
        }

        // Count black elements in the cycle
        int black_count = 0;
        for (int node : cycle) {
            if (s[node - 1] == '0') {
                black_count++;
            }
        }

      
        for (int node : cycle) {
            result[node] = black_count;
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
