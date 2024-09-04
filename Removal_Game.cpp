#include <bits/stdc++.h>
using namespace std;


//Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Define
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";

#define all(x) (x).begin(), (x).end()
#define  MOD (int)(1e9 + 7)
#define MOD1 998244353
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()

#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nl '\n'

//------------------------------------------------------------------------------------------------------------------

// XOR(A to B) = XOR(0 to B) ⊕ XOR(0 to A−1) => we can find that 0 to X using %4 Pattern

int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

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
//Get Binary 
string getBinary(int n){
    bitset<8>b(n);
    return b.to_string();
}
// Kandanes
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

void solve() {
    int n;
    cin>>n;
    vi pre(n,0);
    vi a(n,0);
    input(0,n,a);
    pre[0] = a[0];
    for(int i=1; i < n; i++)pre[i] = pre[i-1]+a[i];
    
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // What will be the state: dp[i][j] = the maximum value i can get from this segment by taking first or the last one
    //dp[i][j] = max(a[i]+dp[i+1][j]+sum[j]-sum[i], a[j]+sum[j-1]-sum[i-1]+dp[i][j-1])
    //Base case will be that when i and j are equal then just you will get that particalualr value at that index
    //if they are greater then just continue
    //to calculate dp we are depenedent on the previous values so we will start from 0 to n

    for(int i=n-1; i >= 0; i--){
        for(int j=0; j < n; j++){
            
            if(i > j)continue;
            if(i == j)dp[i][j] = a[i];
            else {
                int sum = pre[j] - (i > 0 ? pre[i-1] : 0);
                dp[i][j] = max( (sum  - dp[i+1][j]), 
                                (sum  - dp[i][j-1]));
            }


        }
    }
    cout<<dp[0][n-1]<<nl;
}
int32_t main(){
    ff();
    int tc;
    // cin>>tc;
    tc = 1;
    while(tc--){
        solve();
        cout<<nl;
    }
}