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
#define nline "\n"

// Can Easily Identify it is a question of binary search
/*
        [400,100,300,200] and the cinema pays 10% of each 2-nd sold ticket and 20% of each 3-rd sold ticket,
        
        each second sold ticket 100 200 each third ticket 300 How to maximize 

        if we have 400 at 3rd sold ticket it will be 80 and 200 and 300 at secodn ticekts it will be 20+30 =>130

        [100 200 400 300] at nth integer means if it is divisible ok it is clear 

        Lets GO
*/

bool check(int mid, int x, int a, int y, int b, int k, vi &price) {
    // Calculate the number of tickets to be considered
    int count_both = mid / (a * b / __gcd(a, b)); // Number of tickets that can be discounted by both x% and y%
    int count_x = mid / a - count_both;           // Number of tickets that can be discounted by x%
    int count_y = mid / b - count_both;           // Number of tickets that can be discounted by y%

    vi discounts;
    for (int i = 0; i < count_both; ++i) {
        discounts.push_back(x + y);
    }
    for (int i = 0; i < count_x; ++i) {
        discounts.push_back(x);
    }
    for (int i = 0; i < count_y; ++i) {
        discounts.push_back(y);
    }

    sort(discounts.rbegin(), discounts.rend());
    sort(price.rbegin(), price.rend());

    int total = 0;
    for (int i = 0; i < min(mid, sz(discounts)); ++i) {
        total += price[i] * discounts[i] / 100;
        if (total >= k) return true;
    }

    return total >= k;
}

void solve() {
    ff();
    int n;
    cin >> n;
    vi price(n);
    input(0, n, price);
    int x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;

    int l = 1;
    int h = n;
    int ans = -1;
    while (l <= h) {
        int mid = (l + h) / 2; // mid => Number of Tickets
        if (check(mid, x, a, y, b, k, price)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << nline;
}

int32_t main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
        cout << nline;
    }
    return 0;
}
