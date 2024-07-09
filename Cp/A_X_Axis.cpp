#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int maxi = max(a,max(b,c));
    int mini = 1e9;
    for(int i=0; i <= maxi; i++){
        int y = abs(a-i)+abs(b-i)+abs(c-i);
        mini = min(mini,y);
    }
    cout<<mini;
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}