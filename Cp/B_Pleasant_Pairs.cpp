#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define mod (ll)(1e9 + 7)
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }

void solve() {
    // in the question what he had given us
    // the elements are going to be distinct and the maximum element
    // will be less than or equal to 2*length
    // see the elements are distnct and they are set to a limit
    // we can have max multiplication value right

    int n;
    cin>>n;
    vi v(2*n+1,-1);
    for(int i=1; i <= n; i++){
        int t;
        cin>>t;
        v[t] = i;
    }
    // sum will be from 3 to 2n-1
    int ans= 0;
    for(int sum=3; sum < 2*n; sum++){
        for(int i=1; i*i <= sum; i++){
            if(sum%i == 0 && i != sum/i && v[i] != -1 && v[sum/i] != -1 && (v[i]+v[sum/i]) == sum)ans++;
        }
    }
    cout<<ans;

    

}

int32_t main() {
    ff();
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
        cout << endl;
    }
    return 0;
}
