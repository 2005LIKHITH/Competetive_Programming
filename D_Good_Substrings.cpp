#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int M = 1e9 + 9;
const int BASE1 = 5689;
const int BASE2 = 8861;

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
    string str, bad;
    cin >> str >> bad;

    int k;
    cin >> k;

    int n = str.size();

    Hash h(str);

    vector<int> prefixBad(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (bad[str[i - 1] - 'a'] == '0')
            prefixBad[i] = prefixBad[i - 1] + 1;
        else
            prefixBad[i] = prefixBad[i - 1];
    }

   vector<pair<int,int>> hashes;
 
    for (long long i = 0; i < n; i++) 
    {
        for (long long window = 1; window <= (n - i); window++)
        {
            int l = i;
            int r = i + window - 1;
            auto hashValue = h.get(l, r);
            l++;
            r++;
            int badOnes = prefixBad[r] - prefixBad[l - 1];
            if (badOnes <= k)
                hashes.push_back(hashValue);
        }
    }
 
    sort(hashes.begin(), hashes.end());
 
    int uniqueHash = 0;
    for (int i = 1; i < hashes.size(); i++)
    {
        if (hashes[i] != hashes[i - 1])
            uniqueHash++;
    }
    if (hashes.size() == 0)
        cout << 0 << endl;
    else
        cout << uniqueHash + 1 << endl;
}
