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
#define  ppc         __builtin_popcount
#define  ppcll       __builtin_popcountll
#define pi (3.141592653589)
#define PI 3.1415926535897932384626433832795
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }



// A & B <= min(A,B)
// A | B >= max(A,B)
// A & (A-1) = 0 if A is power of 2 except A = 0
// (A | B) + (A & B) = A+B

void solve(){
        int n;
        cin>>n;
        if(n == 3) {cout<<"1 2 3"<<endl; return;}
        // return;

    stack<int>even,odd;
    int strt = 2;
    for(int i=0; i < n/2; i++){
        even.push(strt);
        odd.push(strt+1);
        strt+= 2;
    }
    if((n/2) & 1){
        int p = odd.top();
        p ^= 1;
        odd.pop();
        int q = 1ll << 20;
        p ^= q;
        odd.top() ^= q;
        odd.push(p);
    }
    for(int i=1; i <= n; i++){
        if((n&1) && i == n){
            cout<<0<<" ";
        }
        else if(i & 1){
            cout<<odd.top()<<" ";
            odd.pop();
        }else{
            cout<<even.top()<<" ";
            even.pop();
        }
    }
    cout<<endl;
}


int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        // cout<<endl;
    }
}