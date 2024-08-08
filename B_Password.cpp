#include <bits/stdc++.h>
using namespace std;

#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define nl '\n'
#define MOD (int)(1e9 + 7)
#define MOD1 998244353
#define pi (3.141592653589)
#define INF 1e18

const int M = 1e9 + 9;
const int BASE1 = 5689;
const int BASE2 = 8861;

// Hash Function
struct Hash {
    vector<pair<int, int>> hashes, Pow;

    Hash(const string &s) {
        int n = s.size();
        hashes.assign(n + 1, {0, 0});
        Pow.assign(n + 1, {1, 1});

        for (int i = 0; i < n; i++) {
            hashes[i + 1] = {
                (hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % M,
                (hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % M
            };
            Pow[i + 1] = {
                (Pow[i].first * BASE1) % M,
                (Pow[i].second * BASE2) % M
            };
        }
    }

    pair<int, int> get(int l, int r) {
        l++, r++;
        long long hash1 = (hashes[r].first - (long long)(hashes[l - 1].first * Pow[r - l + 1].first) % M + M) % M;
        long long hash2 = (hashes[r].second - (long long)(hashes[l - 1].second * Pow[r - l + 1].second) % M + M) % M;
        return {hash1, hash2};
    }
};

int32_t main() {
    ff();
    string str;
    cin >> str;

    int n = str.size();

    Hash h(str);

    vector<int> lengths;

    for (int i = 0; i < n; i++) {
        if (h.get(0, i) == h.get(n - i - 1, n - 1)) {
            lengths.push_back(i + 1);
        }
    }

    if (lengths.empty()) {
        cout << "Just a legend" << endl;
        return 0;
    }

    int low = 0, high = lengths.size() - 1, ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int psLength = lengths[mid];
        bool check = false;
        auto hashValue = h.get(0, psLength - 1);
        for (int i = 1; i <= n - psLength - 1; i++) {
            if (h.get(i, i + psLength - 1) == hashValue) {
                check = true;
                break;
            }
        }
        if (check) {
            ans = psLength;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (ans == -1) {
        cout << "Just a legend" << endl;
    } else {
        cout << str.substr(0, ans) << endl;
    }

    return 0;
}
