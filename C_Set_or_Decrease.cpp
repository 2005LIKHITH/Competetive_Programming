#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
#define nline "\n"

bool check(int mid,vi &a,int n,int k,vi &suffix){
    //Here Comes the main thing

    //Looping from taking 0  from last to all
    for(int i=0; i <= min(n-1,mid); i++){
        int rem = mid-i;
        int val1 = (a[0]-rem)*(i+1);
        int val2 = suffix[1]-suffix[n-i];
        if(val1 + val2  <= k)return true;

    }
    return false;

}

void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n,0);
    input(0,n,a)
    sort(all(a));
    int l=0;
    int h = 1e18;
    int ans = -1;
    vi suffix(n+2,0);//To avoid index out of bounds
    suffix[n-1] = a[n-1];
    for(int i=n-2; i >= 0; i--){
        suffix[i] = a[i]+suffix[i+1];
    }
    while(l <= h){
        int mid = (l+h)/2;
        if(check(mid,a,n,k,suffix))h = mid-1,ans = mid;
        else l = mid+1;
    }
    cout<<ans;
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