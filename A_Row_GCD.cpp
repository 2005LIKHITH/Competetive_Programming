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
#define nl '\n'
//------------------------------------------------------------------------------------------------------------------
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n,0),b(m,0);
    input(0,n,a);
    input(0,m,b);

    // for(int i=0; i < m; i++){
    //     int ans = 0;
    //     vi temp = a;
    //     for(int j=0;  j < n; j++){
    //         temp[j] += b[i];
    //         ans = __gcd(ans,temp[j]);
    //     }
    //     cout<<ans<<" ";
    // }
    //Simple logic for optimization we are fixing a and taking b's so what is common  in b exactly differecnes

    int gcd_a = 0;
    for (int i = 1; i < n; i++) {
        gcd_a = gcd(gcd_a, abs(a[i] - a[i-1]));
    }

    // Calculate the result for each b_j
    for (int i = 0; i < m; i++) {
        int result = gcd(gcd_a, a[1] + b[i]);
        cout << result << " ";
    }

}

int32_t main(){
    int tc;
    tc = 1;
    // cin>>tc;
    
    while(tc--){
        solve();
        cout<<nl;
    }
}