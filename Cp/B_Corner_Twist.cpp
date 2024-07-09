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
#define priority_queue<pii, vector<pii>, greater<pii>> minpq;
#define priority_queue<pii> maxpq;
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define  ppc   __builtin_popcount
#define  ppcll   __builtin_popcountll
#define pi (3.141592653589)
#define PI 3.1415926535897932384626433832795

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0)),b(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch;
            cin>>ch;
            a[i][j]=ch-'0';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch;
            cin>>ch;
            b[i][j]=ch-'0';
        }
    }
    for (int i=0; i < n-1; i++) {
        for (int j=0; j < m-1; j++) {
            while (a[i][j] != b[i][j]) {
                a[i][j] = (a[i][j]+1) % 3;
                a[i+1][j+1] = (a[i+1][j+1]+1)%3;
                a[i][j+1] = ((a[i][j+1]+2)%3);
                a[i+1][j] = (a[i+1][j]+2)%3;
            }
        }
    }
    if(a == b)cout<<"YES";
    else cout<<"NO";
}


int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}