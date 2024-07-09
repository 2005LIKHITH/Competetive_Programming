#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod (ll)(1e9 + 7)

int check(int mid,int n,int d,vi &arr){
    int k = 0;
    for(int i=1; i < n; i++){
        k += min(mid,arr[i]-arr[i-1]);
        if(k >= d)return true;
    }
    k += mid;
    return k >= d;
}

void solve(){
    int n,d;
    cin>>n>>d;
    vi arr(n,0);
    for(int i=0; i < n; i++)cin>>arr[i];
    int l = 0;
    int h =  h;
    int ans = -1;
    while(l <= h){
        int mid = l+(h-l)/2;
        if(check(mid,n,d,arr))ans = mid,h=mid-1;
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