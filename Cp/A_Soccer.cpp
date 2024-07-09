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
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    // one sided trend then yes else no
    if(x1 >= y1 && x2 >= y2)cout<<"YES";
    else if(x1 <= y1 && x2 <= y2)cout<<"YES";
    else cout<<"NO";
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