#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod (ll)(1e9 + 7)

int check(int mid,vi req,vi stock,int k,int n){
    int temp = 0;
    for(int i=0; i < n; i++){
        temp += max(0LL,mid*req[i]-stock[i]);
    }
    return temp <= k;
}

int32_t main(){
    ff();
    int n,k;
    cin>>n>>k;
    vector<int>req(n,0),stock(n,0);
    for(int i=0; i < n; i++)cin>>req[i];
    for(int j=0; j < n; j++)cin>>stock[j];
    int l = 0;
    int h = 1e12;
    int ans = -1;
    while(l <= h){
        int mid = l+(h-l)/2;
        if(check(mid,req,stock,k,n)){
            ans = mid;
            l = mid+1;
        }else h = mid-1;
    }
    cout<<ans;
}