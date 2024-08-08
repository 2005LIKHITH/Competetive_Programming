#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n,0);
    for(int i=0; i < n; i++)cin>>a[i];
    int head = 0;
    int tail = 0;
    int ans = 0;
    int sum = 0;
    for(head = 0; head < n; head++){
        sum += a[head];
        while(sum > k){
            sum -= a[tail];
            tail++;
        }
        if(sum == k){
            ans++;
        }
    }
    cout<<ans<<'\n';

}