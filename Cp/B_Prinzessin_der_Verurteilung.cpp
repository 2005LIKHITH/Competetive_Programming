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

//This is a Pure brute force solution due to constraints we can go only upto 3

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<string,int>mp;
    for(int i=0; i < n; i++){
        string str = "";
        for(int j=i; j < n; j++){
            str += s[j];
            mp[str]++;
        }
        
    }
    //for one letter
    string  str = "";
    for(int i =0; i < 26; i++){
        str = ('a'+i);
        if(!mp[str]){
            cout<<str;
            return;
        }
    }
    // for two letter
    for(int i=0; i < 26; i++){
        for(int j=0; j < 26; j++){
            str = ('a'+i);
            str += ('a'+j);
            if(!mp[str]){
                cout<<str;
                return;
            }
        }
    }
    // checking for 3
    for(int i=0; i < 26; i++){
        for(int j=0; j < 26; j++){
            for(int k=0; k < 26; k++){
                str = ('a'+i);
                str += ('a'+j);
                str += ('a'+k);

                if(!mp[str]){
                    cout<<str;
                    return;
                }

            }
        }
    }
}

int32_t main(){
    ff();
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}