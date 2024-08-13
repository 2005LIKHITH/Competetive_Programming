#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define
#define int long long int
#define vi vector<int>
#define pyes cout << "YES\n";
#define pno cout << "NO\n";

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


void solve(){
    int n;
    cin>>n;
    vi a(n+1,0);
    for(int i=1; i <= n; i++){
        a[i] = i+a[i-1];
    }
    // for(auto&it: a )cout<<it<<" ";
    // We Can do something like prefix sum as the standard and use binary seaarch while comparing
    int l = 1;
    int h = n;
    int ans = -1;

    while(l <= h){
        int mid = (l+h)/2;
        cout<<"? "<<mid-l+1<<" ";
        for(int i=l; i < mid+1; i++)cout<<i<<" ";
        cout<<endl;
        int verdict;
        cin>>verdict;

        if(verdict == a[mid]-a[l-1]){
            l = mid+1;
        }else{
            ans = mid;
            h = mid-1;
        }
    }
    cout<<"! "<<ans<<endl;
}

int32_t main() {
    ff();
    int tc;
    cin>>tc;
    while(tc--)solve();
    return 0;
}
