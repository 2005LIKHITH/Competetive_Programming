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
    int n,m;
    cin>>n>>m;
    vector<int>v[m+1];
    for(int i=1;  i <= m; i++)v[i].push_back(0);
    for(int i=1; i <= n; i++){
        int t;
        cin>>t;
        v[t].push_back(i);
    }
    for(int i=1; i <= m; i++)v[i].push_back(n+1);

// we need to maintain two highest becuase when we divide the largest one there will be a chance that it can result less than 
// the remaing highest

    int ans = n+1;
    for(int i=1; i <= m; i++){

        int h1 = 0;
        int h2= 0;
        for(int j=1; j < v[i].size(); j++){
            int temp  = v[i][j]-v[i][j-1]-1;
                if(temp > h1) {
                h2 = h1;
                h1 = temp;
            } else if(temp > h2) {
                h2 = temp;
            }

        }
        ans = min(ans,max(h1/2,h2));
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