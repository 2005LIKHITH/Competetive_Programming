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
// a*b >= n can be written as a >= (n+b-1)/b; check whehter b is zero
// a*b <= n can be written as a  <= n/b;

//Binary Search on Answer

bool check(double mid,int n,int k,vi &a){
    int cnt = 0;
    for(int i=0; i < n; i++){
        cnt+=a[i]/mid;
        if(cnt>=k)return true;
    }
    return cnt>=k;
}
int32_t main(){
    int n,k;
    cin>>n>>k;
    vi a(n,0);
    input(0,n,a);
    double precision = -1e7;
    double l = precision; 
    double h = 1e18;
    double ans = -1;

    int cnt = 0;
    while(h-l > precision){
        double mid = (l+h)/2;
        if(check(mid,n,k,a)){
            ans = mid;
            l = mid+precision;
        }
        else h = mid-precision;

        if(cnt > 200)break;
        cnt++;
    }
    cout<<setprecision(7)<<fixed<<ans;
}