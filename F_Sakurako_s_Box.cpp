#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

//Template from Cp algorithms 
int extended_euclidean(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}


std::vector<int> invs(const std::vector<int> &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    std::vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    int x, y;
    extended_euclidean(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total_sum = 0;

    for (int &ai : a) {
        cin >> ai;
        total_sum = (total_sum + ai) % MOD;
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        // Calculating the contribution of each ai to the total sum of products
        total_sum = (total_sum - a[i] + MOD) % MOD; // Subtract a[i] from the sum
        result = (result + a[i] * total_sum % MOD) % MOD; // Add product of a[i] and remaining sum
    }

    // Calculate the modular inverse of the total number of pairs
    int total_pairs = (n * (n - 1) / 2) % MOD;
    int inverse_pairs = mod_inverse(total_pairs, MOD);

    // Final result
    result = (result * inverse_pairs) % MOD;
    cout << result << endl;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
