#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define

#define int long long int
#define ll int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";

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
const ll M = 1e9+9;
const ll BASE1 = 5689;
const ll BASE2 = 8861;


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
    vector<pair<ll,ll>> hashes, po;
    Hash(string s) {
        hashes.assign(s.size() + 1, {1, 1});
        po.assign(s.size() + 1, {1, 1});
        for (ll i = 0; i < (ll)s.size(); i++) {
            hashes[i + 1] = {
                (hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % M,
                (hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % M
            };
            po[i + 1] = {
                (po[i].first * BASE1) % M,
                (po[i].second * BASE2) % M
            };
        }
    }
 
    pair<ll, ll> get(ll l, ll r) {
        l++, r++;
        ll hash1 = (hashes[r].first - (hashes[l - 1].first * po[r - l + 1].first) % M + M) % M;
        ll hash2 = (hashes[r].second - (hashes[l - 1].second * po[r - l + 1].second) % M + M) % M;
        return {hash1, hash2};
    }
};
void solve()
{
    int n,m;
    cin>>n;
    vector<int> a(n+1), b(n+1), c(n+1);
    int sum=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    
    vector<pair<vector<int>, int>> v;
    v.push_back({a,1});
    v.push_back({b,2});
    v.push_back({c,3});
    sort(v.begin(),v.end());
    do {
        vector<pair<int,int>> ans;
        int flag1=0,flag2=0, flag3=0;
        a = v[0].first;
        b = v[1].first;
        c = v[2].first;
        int sum1=0;
        ans.push_back({v[0].second, 1});
        ans.push_back({v[0].second, 1});
        for(int i=1;i<=n;i++){
            if(!flag1){
                sum1+=a[i];
                ans.back().second=i;
           
                if(sum1>=(sum+2)/3){
                    flag1=1;
                    sum1=0;
                    ans.push_back({v[1].second,i+1});
                    ans.push_back({v[1].second,i+1});
                }
            }
            else if(!flag2){
                sum1+=b[i];
                ans.back().second=i;
    
                if(sum1>=(sum+2)/3){
                    flag2=1;
                    ans.push_back({v[2].second,i+1});
                    ans.push_back({v[2].second,i+1});
                    sum1=0;
                }
            }
            else {
                sum1+=c[i];
                ans.back().second=i;
      
                if(sum1>=(sum+2)/3){
                    flag3=1;
                }
            }
        }
        if(flag1==1 && flag2==1 && flag3==1){
           
            ans.back().second=n;
            sort(ans.begin(), ans.end());
            for(auto it:ans){
                cout<<it.second<<' ';
            }
            cout<<'\n';
            return;
        }
    }while(next_permutation(v.begin(),v.end()));
    cout<<"-1\n";

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
