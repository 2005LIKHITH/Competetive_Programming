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
    string s;
    cin>>s;
    int cnt = 1;
    set<char>st;
    for(int i=0; i < sz(s); ++i){// stringology str ing olog y test t e s t

        st.insert(s[i]);
        if(st.size() > 3){
            cnt++;
            st.clear();
            st.insert(s[i]);
        }
        
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