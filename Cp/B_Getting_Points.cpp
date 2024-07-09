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

int check(int mid,int n,int tp,int l,int p){
    // we get one task for each week
    int sum = 0;
    int tasks = (n+7-1)/7;
    int temp = min(2*mid,tasks);
    sum += temp*p;
    sum += mid*l;
    return sum >= tp;
}

void solve(){
    int n,tp,l,p;
    cin>>n>>tp>>l>>p;
    int lo=0;
    int h = n;
    int ans = 0;
    while(lo <= h){
        int mid = (lo+h)/2;
        if(check(mid,n,tp,l,p)){ans = mid; h = mid-1;}
        else lo = mid+1;
    }
    cout<<n-ans;
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