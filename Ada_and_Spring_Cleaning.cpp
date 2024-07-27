#include <bits/stdc++.h>
using namespace std;

#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define vi vector<int>
#define sz(a) (int)a.size()
#define nl '\n'

const int M = 1e9+9;
const int BASE1 = 5689;
const int BASE2 = 8861;

struct Hash {
    vector<pair<int, int>> hashes, Pow;
    
    Hash(string s) {
        hashes.assign(s.size() + 1, make_pair(0, 0));
        Pow.assign(s.size() + 1, make_pair(1, 1));

        for (int i = 0; i < s.size(); i++) {
            hashes[i + 1] = make_pair((hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % M,
                                      (hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % M);
            Pow[i + 1] = make_pair((Pow[i].first * BASE1) % M,
                                   (Pow[i].second * BASE2) % M);
        }
    }

    pair<int, int> get(int l, int r) {
        l++, r++;
        int hash1 = (hashes[r].first - (hashes[l - 1].first * Pow[r - l + 1].first) % M + M) % M;
        int hash2 = (hashes[r].second - (hashes[l - 1].second * Pow[r - l + 1].second) % M + M) % M;
        return make_pair(hash1, hash2);
    }
};

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    Hash a(s);

    set<pair<int,int>>st;
    for(int i=0; i+k-1 < n; i++){
        auto var = a.get(i,i+k-1);
        st.insert(var);
    }
    cout<<st.size()<<nl;

}

int32_t main() {
    ff();
    int tc;
    cin>>tc;

    while (tc--) {
        solve();
    }
    return 0;
}
