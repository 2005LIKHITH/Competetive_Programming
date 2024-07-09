#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define mod (ll)(1e9 + 7)
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }

int32_t main(){
    ff();
    int n,k,d;
    cin>>n>>k>>d;
    vi a(n);
    input(0,n,a);
    sort(all(a));
    vi v;
    for(int i=1;i < n; i++){
        int val = a[i]-a[i-1];
        if(val <= d)continue;
        else v.push_back((val-1)/d);
    }
    sort(all(v));
    int target = v.size()+1;
    for(auto &it:v){
        if(k >= it)k-=it,target--;
    
    }
    cout<<target;
    
}