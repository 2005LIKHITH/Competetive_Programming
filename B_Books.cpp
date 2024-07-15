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
#define nl endl


// standard Binary Search on Answer Which is here no of Consecutive Books

int check(int mid,vi &a,int n,int t){
    int sum = 0;
    for(int i=0; i < n; i++){
        sum += a[i];
        if(i >= mid){
            sum -= a[i-mid];
        }
        if(i >= mid-1 && sum <= t){
            return true;
        }
    }
    return false;
    
}
int32_t main(){
    ff();
    int n,t;
    cin>>n>>t;
    vi a(n,0);
    input(0,n,a);
    int l = 0;
    int h = n;
    int ans = -1;
    while(l <= h){
        int mid = (l+h)/2;
        if(check(mid,a,n,t))ans = mid, l = mid+1;
        else h = mid-1;
    }
    cout<<ans;
}