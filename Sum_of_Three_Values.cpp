#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>a(n,{0,0});
    for(int i=0; i < n; i++){
        int t;
        cin>>t;
        a[i].first = t;
        a[i].second = i+1;

    }
    sort(a.begin(),a.end());

    for(int i=0; i < n; i++){
        int l = i+1;
        int r = n-1;
        int tempTarget = k-a[i].first;
        while(l < r){
            int p = a[l].first;
            int q = a[r].first;
            // int mid = (p+q)/2;
            if(p+q == tempTarget){
                cout<<a[l].second<<" "<<a[r].second<<" "<<a[i].second<<endl;
                return 0;
            }
            else if(p+q < tempTarget){
                l++;
            }else  r--;

        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}