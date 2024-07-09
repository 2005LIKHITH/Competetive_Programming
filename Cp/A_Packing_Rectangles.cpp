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
// a*b >= n can be written as a >= (n+b-1)/b; check whehter b is zero
// a*b <= n can be written as a  <= n/b;

bool check(int mid,int w,int h,int n){
    int col = mid/w;
    int row = mid/h;
    return(col > 0 && row >= (n+col-1)/col);
 }

int32_t main(){
    ff();
    int w, h, n;
    cin >> w >> h >> n;
    int l = 0;
    int hi = 1e18;
    int ans = 0;
    while(l <= hi){
        int mid = l + (hi - l) / 2;
        if(check(mid, w, h, n)){
            ans = mid;
            hi = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}