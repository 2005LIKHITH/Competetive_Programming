#include<bits/stdc++.h>
#define int long long int
using namespace std;
int pre[200002];
int32_t main(){
    int tc;
    cin>>tc;
    memset(pre,0,sizeof(pre));
    for(int i = 1; i <= 200002; i++){
        int j = i;
        int cnt = 0;
        while(j > 0){
            cnt++;
            j = j/3;
        }
        pre[i] = cnt;
    }
    for(int i=1; i <= 200002; i++){
        pre[i] += pre[i-1];
    }
    while(tc--){
        
        int a,b;
        cin>>a>>b;
        int ans = 0;
        // int cnt = 1;
        int j=a;
        while(j > 0){
            j /= 3;
            ans++;
        }
        ans *= 2;
        ans += pre[b]-pre[a];
        cout<<ans<<endl;

    }
}