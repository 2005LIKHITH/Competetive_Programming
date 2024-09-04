#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define vi vector<int>
#define pyes cout << "YES" << '\n';
#define pno cout << "NO" << '\n';
#define sz(a) (int)a.size()

void solve(){
    int a,b;
    cin>>a>>b;
    int t = a;
    int cnt = 1;
    int ans = 0;
    while(t <= b){
        t += cnt;
        cnt++;
        ans++;
        
    }
    cout<<ans<<endl;
}


signed main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}