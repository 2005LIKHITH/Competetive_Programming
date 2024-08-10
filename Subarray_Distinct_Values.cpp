#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>a(n);
    for(int i=0; i < n; i++)cin>>a[i];
    int ans = 0;
    int head = 0;
    int tail = 0;
    map<int,int>mp;
    for(head = 0; head < n; head++){
        mp[a[head]]++;
        while(mp.size() > k){
            mp[a[tail]]--;
            if(mp[a[tail]] == 0)mp.erase(a[tail]);
            tail++;
        }
        if(mp.size() <= k)ans += (head-tail+1);
    }
    cout<<ans<<endl;
}