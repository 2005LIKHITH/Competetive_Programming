// Jai Shree Ram

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
    int a,b;
    cin>>a>>b;
    int strt = 1; // 4 5 9 3 5 8
    string s = "";

    while(a > 0 || b > 0){
        bool chk = false;
        if(a >0 && (strt & 1)){
            
            s += '0';
            a--;
    
        }
        else if(b > 0 && ((strt & 1) == 0)){
            s += '1';
            b--;
        }
        strt++;
       
    }
    cout<<s;
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