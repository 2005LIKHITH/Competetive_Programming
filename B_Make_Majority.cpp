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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count1 = 0;
    for(auto it: s)if(it == '1')count1++;
    int count0 = 0;
    bool segment = false; 
    
    for (auto ch : s) {
        if (ch == '0' && !segment) {
            segment = true;
            count0++; 
        } else if (ch == '1') {
            segment = false; 
        }
    }
    if(count1 > count0)cout<<"Yes";
    else cout<<"No";

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