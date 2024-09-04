
#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES"<<'\n';
#define pno cout << "NO"<<'\n';

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

int mod_add(int a, int b, int m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int mod_mul(int a, int b, int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int mod_sub(int a, int b, int m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }

int expo(int a, int b, int mod) { int res = 1; while (b > 0) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }

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

string getBinary(int n) {
    bitset<8> b(n);
    return b.to_string();
}

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}
vi findFactors(int x){
    vi result;
    for(int i=1; i*i <= x; i++){
        if(x%i == 0){
            result.push_back(i);
            if(x/i != i)result.push_back(x/i);
        }
        
    }
    return result;
}
int mod_factorial(int n, int mod) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % mod;
    }
    return result;
}


void solve(){
    string s;
    cin>>s;
    // vi del;
    int del = 0;
    int move = 1;
    int ans = 0;
    // int ans = 1;
    for(int i=0; i < sz(s); i++){
        int cons = 1;
        while(i+1 < sz(s) && s[i] == s[i+1])cons++,i++;
        if(cons > 1) del += (cons-1),move = mod_mul(move,cons,MOD1);

    }
    // ans = move;
    //deletinos can be done in del! factorial time right ? 
    for(int i=del; i >= 1; i--){
        move = mod_mul(move,i,MOD1);
    }
    cout<<del<<" "<<move<<nl;
}

signed main() {
    
    ff();
    int tc;
    cin >> tc;
    // tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}
