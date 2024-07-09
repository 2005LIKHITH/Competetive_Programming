#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod (ll)(1e9 + 7)

bool check(int mid, int b, int s, int c, int bCnt, int cCnt, int sCnt, int m, int bp, int sp, int cp) {
    int neededB = max(0LL, bCnt * mid - b);
    int neededS = max(0LL, sCnt * mid - s);
    int neededC = max(0LL, cCnt * mid - c);
    int totalCost = neededB * bp + neededS * sp + neededC * cp;
    return totalCost <= m;
}

int32_t main() {
    ff();
    string s;
    cin >> s;
    int b, su, c;
    cin >> b >> su >> c;
    int bp, sp, cp;
    cin >> bp >> sp >> cp;
    int m;
    cin >> m;

    int bCnt = 0, sCnt = 0, cCnt = 0;
    for (char ch : s) {
        if (ch == 'B') bCnt++;
        if (ch == 'S') sCnt++;
        if (ch == 'C') cCnt++;
    }

    int l = 0;
    int h = 1e13;  // Set an appropriate high value
    int ans = 0;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (check(mid, b, su, c, bCnt, cCnt, sCnt, m, bp, sp, cp)) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
