#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // Prefix sums for counts of '0' and '1'
    vector<int> prefix0(n + 1, 0), prefix1(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix0[i] = prefix0[i - 1] + (s[i - 1] == '0');
        prefix1[i] = prefix1[i - 1] + (s[i - 1] == '1');
    }

    // To store the count of valid substrings
    long long total = 0;

    // Map to store balance frequencies
    unordered_map<int, int> balanceCount;
    for (int i = 0; i <= n; ++i) {
        int balance = prefix0[i] - prefix1[i];
        if (balanceCount.find(balance) != balanceCount.end()) {
            total += balanceCount[balance];
        }
        balanceCount[balance]++;
    }

    cout << total % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
