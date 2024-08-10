#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    int n;
    cin>>n;
    vector<int>a(n,0);
    for(int i =0; i < n; i++){
        cin>>a[i];
    }
    map<int,int>mp;
    int head = 0;
    int tail = 0;
    int cnt = 0;
    for(head = 0; head < n; head++){
        mp[a[head]]++;
        while(mp.size() < head-tail+1){
            mp[a[tail]]--;
            if(mp[a[tail]] == 0)mp.erase(a[tail]);
            tail++;
        }
        if(mp.size() == head-tail+1){
            cnt = max(cnt,head-tail+1);
        }
    }
    cout<<cnt<<endl;
}