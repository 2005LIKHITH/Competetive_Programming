#include<bits/stdc++.h>
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
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define  ppc         __builtin_popcount
#define  ppcll       __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nline "\n"

void solve(){
    int n;
    cin>>n;
    int i; 
    int val1 = 0;
    int val2 = 0;
    //[2 4]
    for(i=1; i <= n/2; i+=2){
        val1 += pow(2,i);
        val1 += pow(2,n-i+1);
        // cout<<val1<<endl;
        //[2 4 ]
        //[16 8 ]
        //[2 4 8 16]
        

    }
    for(i=n/2+1; i <= n; i+=2)val2+=pow(2,i),val2+=pow(2,n-i+1);

    cout<<abs(val1-val2);
}

int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<nline;
    }
}