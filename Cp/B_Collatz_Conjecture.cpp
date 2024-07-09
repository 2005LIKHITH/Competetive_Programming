#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout<<"YES";
#define pno cout<<"NO";
#define ff() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod (ll)(1e9+7)


void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    while(k--){
        x++;
        while(x%y==0){
            x/=y;
        }
    }
    cout<<x;
}

int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}