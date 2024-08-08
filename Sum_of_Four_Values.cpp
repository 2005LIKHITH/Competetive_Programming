#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n, 0);
    map<int, pair<int, int>> mp;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = k - a[i] - a[j];
            if (mp.count(x)) {
                auto p = mp[x];
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    cout << i + 1 << " " << j + 1 << " " << p.first + 1 << " " << p.second + 1 << endl;
                    return 0;
                }
            }
        }
        for (int j = 0; j < i; j++) {
            mp[a[i] + a[j]] = {i, j};
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
