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
    vi a(n);
    input(0, n, a);
    
    // Check if the array is too small to find such indices
    if (n < 3) {
        cout << -1 << endl;
        return;
    }

    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    for (int it : a) {
        maxi.push(it);
        mini.push(it);
    }

    int l = 0;
    int h = n - 1;

    while (l < h) {
        int minTop = mini.top();
        int maxTop = maxi.top();

        if (a[l] != minTop && a[l] != maxTop && a[h] != minTop && a[h] != maxTop) {
            cout << l + 1 << " " << h + 1 << endl;
            return;
        }

        if (a[l] == minTop) {
            l++;
            mini.pop();
        } else if (a[l] == maxTop) {
            l++;
            maxi.pop();
        } else if (a[h] == minTop) {
            h--;
            mini.pop();
        } else if (a[h] == maxTop) {
            h--;
            maxi.pop();
        }
    }

    cout << -1 << endl;
}

int32_t main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
