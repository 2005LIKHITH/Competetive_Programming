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
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n,0);
    f(i,0,n){
        a[i] = i; 
    }
    int left = 0, right = n - 1;
    while (left < right) {
        swap(a[left], a[right]);
        left++;
        right--;
    }
    left = n - m;
    right = n - 1;
    while (left < right) {
        swap(a[left], a[right]);
        left++;
        right--;
    }
    for (auto &it: a) {
        cout<<it+1<<" ";
    }


}
int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<nline;
    }
}
