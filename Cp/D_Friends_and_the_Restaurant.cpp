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
    //Lmao
    int n;cin>>n;vi a(n,0),b(n,0);input(0,n,a);input(0,n,b);vi res;for(int i=0; i < n; i++){int t = b[i]-a[i]; res.push_back(t); }sort(all(res));int cnt = 0;    
    int i=0;
    int j = n-1;
    // our motive is to decresase the neg value 
    // two friends going to restaurent iz optimal
    while(i < j){
        int sum = res[i]+res[j];
        if(sum < 0)i++;
        else cnt++,i++,j--;
    }
    cout<<cnt;

}
int32_t main(){
    ff();//free fire khelte ho?
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}