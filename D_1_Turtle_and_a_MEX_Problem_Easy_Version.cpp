#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define
#define ll long long
#define int long long int
#define vi vector<int>
#define pyes cout << "YES" << '\n';   
#define pno cout << "NO" << '\n';
#define db long double

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

ll mex(vector<ll> &arr) {
	ll n = arr.size();
	set<ll> hs;
	for(ll i = 0; i <= n + 1; i++) hs.insert(i);
 
	for(auto i : arr) hs.erase(i);
 
	hs.erase(*(hs.begin()));
 
	return *(hs.begin());
}
void solve() {
    int n,m;
    cin>>n>>m;
    v   ector<int>a[n];
    for(int i =0;  i< n; i++){
        int t;
        cin>>t;
        for(int j=0; j < t; j++){
            int temp;
            cin>>temp;
            a[i].push_back(temp);
        }
    }
    int maxi = 0;
    for(int i=0; i < n; i++){
        maxi = max(maxi,mex(a[i]));
    }
    if(maxi >= m){
        cout<<(m+1)*maxi<<nl;
        return;
    }
    int ans = (maxi + 1) * maxi + (m * (m + 1)) / 2 - (maxi * (maxi + 1)) / 2;
	cout << ans << nl;
}


int32_t main() {
    ff();
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
}
