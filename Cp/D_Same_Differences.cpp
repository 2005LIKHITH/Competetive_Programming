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
    map<int,int> u;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
    cin>>v[i];
    int diff=(v[i]-(i+1));
    u[diff]++;
    } 
    int ans=0;
    for(auto it:u)
    {
    int freq=it.second;
    int num=((freq)*(freq-1))/2;
    ans+=num;
    }
    cout<<ans;
}

int32_t main() {
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}