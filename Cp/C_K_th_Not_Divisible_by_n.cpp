#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod (ll)(1e9 + 7)

void solve(){
    int n,k;
    cin>>n>>k;
    int result = k + (k - 1) / (n - 1);
    
    cout<<result;
}

int32_t main(){
    ff();
    int tc;
    cin >> tc;
    while(tc--){
        solve();
        cout << endl;
    }
}
