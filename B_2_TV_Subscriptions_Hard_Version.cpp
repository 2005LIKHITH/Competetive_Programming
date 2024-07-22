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

void solve(){
    int n,k,d;
    cin>>n>>k>>d;
    vi a(n,0);
    input(0,n,a);
    //Kind of fixed size sliding window and set
    int ans = 1e9;
    map<int,int>mp;
    for(int i=0; i < n; i++){
        mp[a[i]]++;
        if(i >= d){
            mp[a[i-d]]--;
            if(mp[a[i-d]] == 0)mp.erase(a[i-d]);
        }
        if(i >= d-1){
            int t = mp.size();
            ans = min(ans,t);
        }
    }
    cout<<ans;
}

int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<nl;
    }
}