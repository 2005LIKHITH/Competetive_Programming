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
#define PI 3.1415926535897932384626433832795

//only way is to minimize the maximum time taken for the individual machine

bool check(int mid,int n,int k,vi &a){
    int sum = 0;
    for(int i=0; i < n; i++){
        sum += mid/a[i];
        if(sum >= k)return true;
    }
    return sum >= k;
}

int32_t main(){
    ff();
    int n,target;
    cin>>n>>target;
    vi a(n,0);
    input(0,n,a);
    int l = 0;
    int h = 1e18;
    int ans = -1;
    while(l <= h){
        int mid = l+(h-l)/2;
        if(check(mid,n,target,a)) h = mid-1,ans = mid;
        else l = mid+1;
    }
    cout<<ans;
}