#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>a(n);
    for(int i=0; i < n; i++){
        int t;
        cin>>t;
        a[i] = {t,i+1};
    }

    sort(a.begin(),a.end());
    // 1 2 5 7 
    int i=0;
    int j = n-1;
    for(; i < j; i = i+1-1){
        if(a[i].first+a[j].first == k){
            cout<<a[i].second<<" "<<a[j].second<<endl;
            return 0;
        }
        else if(a[i].first +a[j].first < k){
            i++;
        }
        else j--;
    }
    cout<<"IMPOSSIBLE"<<endl;
}