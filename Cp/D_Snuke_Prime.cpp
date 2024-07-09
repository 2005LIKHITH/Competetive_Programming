#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define mod (int)(1e9 + 7)
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }

// vi diff(1e6 , 0);

void solve(){
    ll n,x;
    cin>>n>>x;
    ll a[n],b[n],c[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    set<ll>st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
        st.insert(b[i]+1);
    }
    int idx=0;
    map<int,int>mp;
    for(auto it:st){
        mp[it]=idx;
        idx++;
    }
    int compressed_size=idx;
    vector<ll>cost(compressed_size);
    for(int i=0;i<n;i++){
        cost[mp[a[i]]]+=c[i];
        if(mp[b[i]+1]<compressed_size){
            cost[mp[b[i]+1]]-=c[i];
        }
    }
    for(int i=1;i<compressed_size;i++){
        cost[i]+=cost[i-1];
    }
    ll ans=0;
    vector<ll>days(st.begin(),st.end());
    for(int i=0;i<compressed_size-1;i++){
        ll span=days[i+1]-days[i];
        ans+=min(cost[i],x)*span;
    }
    cout<<ans<<endl;

}

int32_t main() {
    //we cannot apply this to constrains having array 1e9
    // f
    
    solve();
}
