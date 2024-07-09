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

void solve(){
    int n,m;
    cin>>n>>m;
    int maxi = INT_MIN;
    pair<int,int>maxIndex = {-1,-1};
    vector<vector<int>>a(n,vector<int>(m,0));
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin>>a[i][j];
            if(a[i][j] > maxi){
                maxi = a[i][j];
                maxIndex.first = i;
                maxIndex.second = j;
            }
        }
    }
    int r = maxIndex.first+1;
    int c = maxIndex.second+1;
    int len = max(r,n-r+1)*max(c,m-c+1);
    cout<<len;
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