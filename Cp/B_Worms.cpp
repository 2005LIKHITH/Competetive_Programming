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
#define PI 3.1415926535897932384626433832795


int32_t main(){
    ff();
    int n;
    cin>>n;
    vi a(n,0);
    input(0,n,a);
    vi pre(n,0);
    pre[0] = a[0];
    for(int i=1; i < n; i++){
        pre[i]  = pre[i-1]+a[i];
    }
    // 2 7 3 4 9
    // 2 9 12 16 25
    //1 5 3
    int m;
    cin>>m;
    while(m--){
        int p;
        cin>>p;
        int ans = lower_bound(pre.begin(),pre.end(),p)-pre.begin();
        cout<<ans+1<<endl;
        
    }
}