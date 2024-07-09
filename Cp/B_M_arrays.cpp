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
    int n,k;
    cin>>n>>k;
    vi a(n,0);
    vector<int>mp(k,0);
    for(int i=0; i < n; i++){
        cin>>a[i];
        a[i]%=k;
        mp[a[i]]++;
    }
    int ans = 0;
    if(mp[0])ans++;
    for(int i=1; i < k; i++){
        if(mp[i]){
            if(abs(mp[i]-mp[k-i]) <= 1)ans++;
            else ans += abs(mp[i]-mp[k-i]);
            mp[k-i] = 0;
        }
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