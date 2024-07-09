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
    int n;
    cin>>n;
    vi a(n,0);
    input(0,n,a);
    /*
        0 0 0 0 0 
        1 0 0 0 0
        1 1 0 0 0 
        1 1 2 3 -3

        0 0 0 0 0
        1 0 0 0 0
        1 1 0 0 0
        1 2 0 0 0
        1 2 1 -1 0
        1 2 3 4 -3


    */

    vi pre(n,0);
    pre[0] = a[0];

    for(int i=1; i < n; i++){
        pre[i] = pre[i-1]+a[i];
    }
    if(pre[n-1]){
        pno;
        return;
    }
    for(int i=0; i < n; i++){
        if(pre[i] < 0){pno return;}
    }
    for(int i=0; i < n; i++){
        if(pre[i] == 0){
            for(int j = i; j < n; j++){
                if(pre[j] != 0){
                    pno
                    return;
                }
            }
            break;
            
        }
    }
    pyes
}


int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}