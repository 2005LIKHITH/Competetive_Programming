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
    int n;
    cin>>n;
    vi a(n,0);
    // Usig map of map
    int x,y;
    cin>>x>>y;
    input(0,n,a);
    map<int,map<int,int>>mp;//learn this
    int cnt = 0;
    for(int i=0 ; i < n; i++){
        cnt +=  mp[(x-a[i]%x)%x][a[i]%y];
        mp[(a[i]%x)][a[i]%y]++;
    }
    cout<<cnt;
    
    
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