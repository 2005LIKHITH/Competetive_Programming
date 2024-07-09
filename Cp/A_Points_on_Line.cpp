#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout<<"YES";
#define pno cout<<"NO";
#define ff() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod (ll)(1e9+7)

int findLow(int high,vector<int>&arr,int n,int d){
    int l = 0;
    int h = n-1;
    int ans = -1;
    while(l <= h){
        int mid = l+(h-l)/2;
        if(abs(arr[high]-arr[mid]) <= d)ans = mid,h = mid-1;
        else l = mid+1;
    }
    return ans;
}

int32_t  main(){
    ff();
    int n,d;
    cin>>n>>d;
    vector<int>arr(n,0);
    for(int i=0; i < n; i++)cin>>arr[i];
    int ans  = 0;
    for(int i=2; i < n; i++){
        int lowest_point = findLow(i,arr,n,d);
        if(lowest_point!= -1){int k = i-lowest_point;
        if(i>=2)ans += (k*(k-1))/2;
        }

    }
    cout<<ans;
}