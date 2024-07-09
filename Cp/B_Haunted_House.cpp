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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cntOnes = 0;
    f(i,0,n){if(s[i] == '1')cntOnes++;}
    // ithne -1 tho honge hi honge
    // we need to find the nearest 0 for everone 1;
    int ans = 0;
    int ptr = n-1;
    rf(i,n-1,cntOnes){
        ptr = min(i,ptr);
        if(s[i] =='0'){
            cout<<ans<<" ";
            continue;
        }

        while(ptr >= 0 && s[ptr] != '0'){
            ptr--;
        }
        if(ptr >= 0){
            swap(s[ptr],s[i]);
            ans += (i-ptr);
        
        }
        cout<<ans<<" ";
    }
    while(cntOnes--)cout<<-1<<" ";
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