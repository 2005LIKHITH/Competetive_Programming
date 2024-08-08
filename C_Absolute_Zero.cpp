#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES" << nl;
#define pno cout << "NO" << nl;

#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)
#define MOD1 998244353
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int)a.size()

#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nl '\n'
#define sp " "

const int M = 1e9+9;
const int BASE1 = 5689;
const int BASE2 = 8861;

//------------------------------------------------------------------------------------------------------------------

void solve() {
    //Rememeber this Approach

    //Approach in bits

    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &it:v)cin>>it;
    bool f1=false,f2=false;
    for(auto it:v){
        if(it&1)f1=true;
        else f2=true;
    }
    if(f1 && f2){
        cout<<-1<<endl;
        return;
    }
    vector<int>ans;
    for(int i=29;i>=0;i--){
        ans.push_back(1<<i);
    }
    if(f2)ans.push_back(1);
    cout<<ans.size()<<nl;
    for(auto it:ans){
        cout<<it<<sp;
    }
    cout<<endl;
}

int32_t main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
