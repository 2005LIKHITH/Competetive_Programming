#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define

#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES" << nl;
#define pno cout << "NO" << nl;

#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)
#define MOD1 998244353
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int)a.size()

#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nl '\n'
#define sp " "

const int M = 1e9+9;
const int BASE1 = 5689;
const int BASE2 = 8861;

//------------------------------------------------------------------------------------------------------------------

// XOR(A to B) = XOR(0 to B) ⊕ XOR(0 to A−1) => we can find that 0 to X using %4 Pattern

int mod_add(int a, int b, int m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int mod_mul(int a, int b, int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int mod_sub(int a, int b, int m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }

int expo(int a, int b, int mod) { int res = 1; while (b > 0) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }

// To get All Prime Factors
vi primeFactorization(int n) {
    vi factorization;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1) {
        factorization.push_back(n);
    }
    return factorization;
}

// Sieve of Eratosthenes function
vi sieve(int limit) {
    vi primes;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

// Get Binary 
string getBinary(int n) {
    bitset<8> b(n);
    return b.to_string();
}

// Kadane's algorithm
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}

// Hash Function

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



struct Node
{
    int childReferences[26];
    int stringEndingHere;
    int stringsEndingBelow;
    Node()
    {
        for (int i = 0; i < 26; i++)
            childReferences[i] = -1;
        stringEndingHere = 0;
        stringsEndingBelow = 0;
    }
};

struct Trie
{
    int root;
    vector<Node> nodes;
    Trie()
    {
        root = 0;
        nodes.push_back(Node());
    }

    void precomputeSpecialStringsBelow(int currentNode)
    {
        nodes[currentNode].stringsEndingBelow = nodes[currentNode].stringEndingHere;
        for (int i = 0; i < 26; i++)
        {
            if (nodes[currentNode].childReferences[i] != -1)
                nodes[currentNode].stringsEndingBelow += nodes[nodes[currentNode].childReferences[i]].stringsEndingBelow;
        }
    }

    void addRecursively(string &a, int currentNode, int index)
    {
        if (index == a.size())
        {
            nodes[currentNode].stringEndingHere++;
            precomputeSpecialStringsBelow(currentNode);
            return;
        }
        int child = nodes[currentNode].childReferences[a[index] - 'a'];
        if (child == -1)
        {
            nodes[currentNode].childReferences[a[index] - 'a'] = nodes.size();
            nodes.push_back(Node());
            child = nodes[currentNode].childReferences[a[index] - 'a'];
        }
        addRecursively(a, child, index + 1);
        precomputeSpecialStringsBelow(currentNode);
    }

    void addString(string a)
    {
        addRecursively(a, root, 0);
    }

    bool searchString(string a)
    {
        int currentNode = root;
        for (auto ch : a)
        {
            int characterIndex = ch - 'a';
            if (nodes[currentNode].childReferences[characterIndex] == -1)
                return false;
            currentNode = nodes[currentNode].childReferences[characterIndex];
        }
        return nodes[currentNode].stringEndingHere > 0;
    }

    int commonPrefixes(string a)
    {
        int currentNode = root;
        for (auto ch : a)
        {
            int characterIndex = ch - 'a';
            if (nodes[currentNode].childReferences[characterIndex] == -1)
                return 0;
            currentNode = nodes[currentNode].childReferences[characterIndex];
        }
        return nodes[currentNode].stringsEndingBelow;
    }
};

void solve() {

    int n;
    cin>>n;
    vi a(n,0);
    input(0,n,a);
    int maxi = 0;
    for(int i=n-1; i >= 0; i = i-2){
        maxi = max(maxi,a[i]);
    }
    cout<<maxi<
}

int32_t main() {
    ff();
    int tc;
    cin >> tc;
    // tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}
