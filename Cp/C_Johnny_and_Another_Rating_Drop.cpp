// Jai Shree Ram 
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
bool prime(int x) { if (x==1) return 0; for (int i=2;i<=x*x;++i) if (x%i==0) return 0; return 1; }

void solve(){
    int n;
    cin>>n;
    int ans = 0;
    while(n){
        ans += n;
        n >>=1;
    }
    cout<<ans;
}


int32_t main(){
    ff();
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}