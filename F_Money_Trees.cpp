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
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nl '\n'


void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n,0);
    input(0,n,a);
    vi b(n,0);
    input(0,n,b);
    
    int tail = 0;
    int sum = 0;
    int ans = 0;

    for(int head = 0; head < n; head++){
        if(head > 0 && b[head-1]%b[head] != 0)sum = 0,tail = head;
        
        sum += a[head];

        while(tail <= head && sum > k){
            sum -= a[tail];
            tail++;
        }
        ans = max(ans,head-tail+1);

    }
    cout<<ans;
}

int32_t main(){
    ff();
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<nl;
    }
}