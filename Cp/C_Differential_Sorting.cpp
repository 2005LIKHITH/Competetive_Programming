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
    vi a(n,0);
    input(0,n,a);
    vi p;
    p = a;
    sort(all(p));
    if(p == a){
        cout<<0<<endl;
        return;
    }
    if(a[n-1] < a[n-2]){
        cout<<-1<<endl;
        return;
    }
    if(abs(a[n-1]-a[n-2]) >= 1e18){
        cout<<-1;
        return;
    }
    if(a[n-1] >= 0){//Basically this means the array has negative integers so who logice of sorting will be collapsed
        cout<<n-2<<endl;
        for(int i=0; i < n-2; i++){
            cout<<i+1<<" "<<n-1<<" "<<n<<endl;
        }
    }
    else cout<<-1<<endl;
}

int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        
    }
}