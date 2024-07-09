#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define mod (int)(1e9 + 7)
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi chk(n+1,0);
    int cnt = 0;
    for(int i=1; i <=n; i++){
        for(int j=i; j <= n; j+=i){
            if(s[j-1] == '1')break;
            if(chk[j] == 0){
                cnt += i;
                chk[j] = 1;
            }
        }
    }
    cout<<cnt;
}

int32_t main(){
    ff();//Free Fire math khelo Vro Sehat keliye hani karah hai
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}