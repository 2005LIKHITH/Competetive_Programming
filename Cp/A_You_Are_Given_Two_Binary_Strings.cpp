#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define mod (int)(1e9 + 7)
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define lcm(a,b) (a*b)/__gcd(a,b)

int convert(string s){
    int n = s.size()-1;
    int ans = 0;
    int i = 0;
    reverse(all(s));
    while(i <= n){
        ans += (s[i]-'0')*(pow(2,i));
        ++i;
    }
    return ans;
}

void solve(){
    string x,y;
    cin>>x>>y;
    int p,q = 0;
    // converting binary to int
    p = convert(x);
    q = convert(y);
    
    q *= pow(2,k)
}



int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}