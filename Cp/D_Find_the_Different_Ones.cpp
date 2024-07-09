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

void solve() {
    int n;
    cin >> n;
    vi a(n+1, 0); 
    input(1, n+1, a); 
    int q;
    cin >> q;
    vi uniq;
    for(int i=1; i < n ; i++){
        if(a[i] != a[i+1])uniq.push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
    //     map<int, vector<int>> mp;
    //     for (int i = l; i <= r; i++) {
    //         mp[a[i]].push_back(i);
    //     }
    //     //if we are able to decrease this oops o(n) to less then we can do someting

    //     if (mp.size() <= 1) {
    //         cout << -1 << " " << -1 << endl;
    //     } else {
    //         auto it = mp.begin();
    //         cout << it->second[0] << " ";
    //         ++it;
    //         cout << it->second[0] << endl;
    //     }
    // }
    // cout<<endl;
    // optmizing things

    // Got to learn usecase of upperbound and lowerbound

    int t = lower_bound(uniq.begin(),uniq.end(),l)-uniq.begin();
    if(t < uniq.size() and uniq[t] < r){
        cout<<uniq[t]<<" "<<uniq[t]+1<<endl;
    }else cout<<"-1 -1"<<endl;


    }
    cout<<endl;
}

int32_t main() {
    ff(); 
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
