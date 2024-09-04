#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    map<int,int>mp;
    vector<vector<int>>a(n);
    for(int i=0; i < n; i++){
        int l;
        cin>>l;
        for(int j=0; j < l; j++){
            int t;
            cin>>t;
            a[i].push_back(t);
            mp[t]++;

        }
    }
    for(auto &vit: a){
        bool chk = true;
        for(auto &it: vit){
            if(mp[it] == 1){
                chk = false; 
                break;
            }
        }
        if(chk){
            cout<<"YES"<<endl;
            return;
        }
        
    }
    cout<<"NO"<<endl;
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();

    }
}