#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod (ll)(1e9 + 7)

int32_t main(){
    ff();
    int n;
    cin>>n;
    vi arr(n,0);
    for(int i=0; i < n; i++)cin>>arr[i];
    int k;
    cin>>k;
    sort(arr.begin(),arr.end());
    while(k--){
        int t;
        cin>>t;
        int pos = upper_bound(arr.begin(),arr.end(),t)-arr.begin();
        cout<<pos<<endl;
    }
}