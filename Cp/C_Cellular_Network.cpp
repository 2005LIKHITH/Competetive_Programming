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
#define priority_queue<pii, vector<pii>, greater<pii>> minpq;
#define priority_queue<pii> maxpq;
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define  ppc   __builtin_popcount
#define  ppcll   __builtin_popcountll
#define pi (3.141592653589)
#define PI 3.1415926535897932384626433832795

bool check(int mid, vi &tower, vi &cities) {
    int n = cities.size();
    int m = tower.size();
    // -2 0 

    int i=0;
    int j=0;
    while(i < n && j < m){
        if(abs(tower[j]-cities[i]) <= mid)i++;
        else j++;
    }
    return i==n;
}

int32_t main() {
    ff();
    int n, m;
    cin >> n >> m;
    vi cities(n, 0), tower(m, 0);
    input(0, n, cities);
    input(0, m, tower);

    int l = 0;
    int h = 1e10;
    int ans = 0;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (check(mid, tower, cities)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
   
}
