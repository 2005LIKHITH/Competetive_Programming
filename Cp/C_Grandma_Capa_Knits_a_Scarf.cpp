#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define mod (ll)(1e9 + 7)
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }

int mini(string s, char ch) {
    int i = 0, j = s.size() - 1;
    int deletions = 0;
    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else if (s[i] == ch) {
            deletions++;
            i++;
        } else if (s[j] == ch) {
            deletions++;
            j--;
        } else {
            return INT_MAX; 
        }
    }
    return deletions;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int minDeletions = INT_MAX;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        int deletions = mini(s, ch);
        minDeletions = min(minDeletions, deletions);
    }

    if (minDeletions == INT_MAX) {
        cout << -1;
    } else {
        cout << minDeletions;
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
    return 0;
}
