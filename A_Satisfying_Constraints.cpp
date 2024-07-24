#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int l = -1e9;
    int h = 1e9;
    vector<int>a;
    while(n--){
        int x,y;
        cin>>x>>y;
        if(x==1)l = max(l,y);
        else if(x==2)h = min(h,y);
        else a.push_back(y);
    }
    if(l > h){
        cout<<0<<endl;
        return;
    }
    
    int ans = h-l+1;
    for(auto &it: a){
        if(it >= l && it <= h)ans--;
    }
    cout<<ans<<'\n';

}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        
    }
}