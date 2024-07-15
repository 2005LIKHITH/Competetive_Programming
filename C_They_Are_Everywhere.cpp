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
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nl endl

bool check(int mid, const string &s, int n, const set<char> &st) {
    map<char, int> freq;
    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        if (freq[s[i]] == 0) {
            distinctCount++;
        }
        freq[s[i]]++;

        if (i >= mid) {
            freq[s[i - mid]]--;
            if (freq[s[i - mid]] == 0) {
                distinctCount--;
                freq.erase(s[i-mid]);
            }
        }

        if (i >= mid - 1 && distinctCount == st.size()) {
            return true;
        }
    }

    return false;
}

int32_t main() {
    ff();
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> st(all(s));
    int l = st.size();  
    int h = n;
    int ans = n;

    while (l <= h) {
        int mid = (l + h) / 2;
        if (check(mid, s, n, st)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << nl;
    return 0;
}
