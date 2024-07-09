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


void solve (){
        int n,m;
        cin>>n>>m;
        vi a(n,0),b(m,0);

        vi maxi(n,0);
        vi pre(n,0);
        input(0,n,a);
        input(0,m,b);
        maxi[0] = a[0];
        pre[0] = a[0];
        for(int i=1; i < n; i++){
            pre[i] = a[i]+pre[i-1];
            maxi[i] = max(maxi[i-1],a[i]);

        }
        for(auto &it:b){
            auto z = upper_bound(maxi.begin(),maxi.end(),it)-maxi.begin()-1;
            if(z > -1)cout<<pre[z]<<" ";
            else cout<<0<<" ";
        }

    }

int32_t main(){
    // standard binary serach using lower ana upperbound
    ff();
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}