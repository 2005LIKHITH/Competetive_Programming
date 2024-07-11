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

int check(int mid,vector<pair<int,int>>&a,int n){
    int cnt = 0;
    int strt = 0;
    int end = mid-1;
    for(int i=0; i < sz(a); i++){
        if(a[i].first >= end && a[i].second >= strt){
            cnt++;
            strt++;
            end--;
            
        }
        if(cnt == mid)return 1;
    }
    return 0;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>a(n,{0,0});
    for(int i=0; i < n; i++){
        int t,s;
        cin>>t>>s;
        a[i] = {t,s};
    }
    // You need Ai friends to be rich and Bi friedns to be poor

    // one observation is that if you cant invite x number of people to the party it is obvious that you
    // cannot invite x+1,x+2 numbers to the party
    // Intutino for the binary search

    // Now all we need to figure out is how to write the check funtcion
    // [{1,2} {2,1} {1,1}]  
//     1       2      3

    int l =1;
    int h = n;
    int ans = 0;
    while(l <= h){
        int mid = (l+h)/2;
        if(check(mid,a,n)){
            ans = mid;
            l = mid+1;
        }else h = mid-1;
    }
    cout<<ans;
}

int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<nline;
    }
}