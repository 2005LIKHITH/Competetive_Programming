#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;

        int x_moves = (x + k - 1) / k;
        int y_moves = (y + k - 1) / k;

        int mini = min(x_moves, y_moves);
        int maxi = max(x_moves, y_moves);

        int ans = mini + maxi + (maxi - mini);
        if (x_moves > y_moves) ans--;

        cout << ans << endl;
    }

    return 0;
}
