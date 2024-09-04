#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define vi vector<int>
#define pyes cout << "YES" << '\n';
#define pno cout << "NO" << '\n';
#define sz(a) (int)a.size()

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int c = pow(n,0.5);
    if(c*c != n){
        pno
        return;
    }
    for(int i=1; i <= c-2; i++){
        if(s[i*c+c-1] != '1' || s[i*c] != '1'){
            pno
            return;
        }
        for(int j=1; j <= c-2; j++){
            if(s[j+i*c] != '0'){
                pno
                return;
            }
        }
    }
    pyes
}
 
signed main() {
    ff();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
