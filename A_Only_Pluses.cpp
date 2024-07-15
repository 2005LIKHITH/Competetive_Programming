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
#define  ppc         __builtin_popcount
#define  ppcll       __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nline "\n"


void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int arr[3] = {a,b,c};
    sort(arr,arr+3);

    for(int i=0; i < 5; i++){
        if(arr[0] <= arr[1] && arr[0] <= arr[2])arr[0]++;
        else if(arr[1] <= arr[0] && arr[1] <= arr[2])arr[1]++;
        else arr[2]++;
    }
    cout<< arr[0]*arr[1]*arr[2];
    
}
int32_t main(){
    ff();
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<nline;
    }
}

