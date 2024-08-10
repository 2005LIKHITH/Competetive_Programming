#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second < b.second;
}
int32_t main(){
    int n;
    cin>>n;
    vector<pair<int,int>>a(n,{0,0});
    for(int i=0; i < n; i++){
        int p,q;
        cin>>p>>q;
        a[i].first = p;
        a[i].second = q;
    }
    sort(a.begin(),a.end(),cmp);
    int cnt = 0;
    int prev = -1;
    for(int i=0; i < n; i++){
        if(a[i].first >= prev)cnt++,prev = a[i].second;;
        
    }
    cout<<cnt<<endl;
}