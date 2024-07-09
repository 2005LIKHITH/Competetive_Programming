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

void solve(){
    int n;
    cin>>n;
    char ch;
    cin>>ch;
    string s;
    cin>>s;
    // minimum number of operation so kind of g
    bool chk = true;
    int pos = -1;
    for(int i=0; i < s.size(); i++){
        char c = s[i];
        if(c == ch)pos = i;
        if(c != ch)chk = false;
    }
    if(chk){
        cout<<"0";
        return;
    }
    if(pos == -1){
        cout<<"2\n";
        cout<<n-1<<" "<<n;
    }
    else if(pos >= n/2){
        cout<<"1\n";
        cout<<pos+1;
    }
    else{
        cout<<"2\n";
        cout<<n-1<<" "<<n;
    }
}

int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }

}