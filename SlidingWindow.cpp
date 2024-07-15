#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {5,3,0,-2,8,12};
    int n = 6;
    
    // max window of size k

    int k = 3;
    // if(k > n)return INT_MAX;

    // int sum = 0;

    // for(int i=0; i < k; i++){
    //     sum += a[i];
        
    // }
    // ans = sum;
    // for(int i = k; i < n; i++){
    //     sum += a[i];
    //     sum -= a[i-k];
    //     ans = max(ans,sum);
    // }
    // cout<<ans<<endl;

    //Mark 

    //Fancy Implementation

    int sum = 0;
    int ans = -1e9;

    for(int i=0; i < n; i++){
        sum += a[i];
        if(i >= k)sum -= a[i-k];
        if(i >= k-1)ans = max(ans,sum);
    }
    cout<<ans;

}