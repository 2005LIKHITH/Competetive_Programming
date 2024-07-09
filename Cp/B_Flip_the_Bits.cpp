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
    string s1, s2;
    cin >> s1 >> s2;

    // making substrings
    vector<pair<int, int>> vp;
    int oneCnt = 0;
    int zeroCnt = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '1') oneCnt++;
        else zeroCnt++;
        if (oneCnt == zeroCnt) {
            vp.push_back({j, i});
            j = i + 1;
        }
    }

    for (auto &it : vp) {
        int start = it.first;
        int end = it.second;
        if (s1[start] == s2[start]) continue;
        else {
            for (int j = start; j <= end; j++) {
                if (s1[j] == '0') s1[j] = '1';
                else s1[j] = '0';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int32_t main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
        cout << endl;
    }
    return 0;
}
