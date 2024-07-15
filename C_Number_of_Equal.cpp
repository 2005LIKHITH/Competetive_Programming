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


int32_t main(){
    ff();
    int n;
    cin>>n;
    int m;
    cin>>m;
    vi a(n,0);
    input(0,n,a);
    map<int,int>mp;
    for(int i=0; i < m; i++){
        int t;
        cin>>t;
        mp[t]++;
    }
    int cnt = 0;
    for(auto it: a){
        if(mp[it] != 0)cnt += mp[it];// 1+1
    }
    cout<<cnt;

}