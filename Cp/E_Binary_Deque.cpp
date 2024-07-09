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

void solve(){
    // Here we dont know what is the distance of nearest 1 from the point where we are so we use perfix sums
    int n,k;
    cin>>n>>k;
    vi a(n+1,0);
    input(1,n+1,a);
    vi pre(n+1,0);
    // pre[0] = a[0];
    for(int i=1 ; i <=n; i++){
        pre[i] = pre[i-1]+a[i];
    }
    int miniMoves = 1e9;
    if(pre[n] < k){
        cout<<-1;
        return;
    }
    // Remember the technique
    for(int i=1; i <= n; i++){
        int sum = pre[i-1]+k;
        if(sum > pre[n])continue;
        auto t = upper_bound(pre.begin(),pre.end(),sum)-pre.begin()-1;
        int ans = n-(t-i+1);
        miniMoves = min(miniMoves,ans);
    }
    cout<<miniMoves;
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