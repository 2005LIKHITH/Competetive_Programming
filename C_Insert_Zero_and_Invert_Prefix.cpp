
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
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

int mex(vector<int> const& A) {
    set<int> b(A.begin(), A.end());

    int result = 0;
    while (b.count(result))
        ++result;
    return result;
}
void solve(){
    int n;
    cin>>n;
    vi a(n);
    input(0,n,a);
    reverse(all(a));
    vi rez;
    int cnt = 1;
    if(a[0] == 1){
        pno
        return;
    }
    pyes
    for(int i=1; i < n; i++){
        if(a[i] != a[i-1]){
            rez.push_back(cnt);
            cnt = 1;

        }else cnt++;
    }
    rez.push_back(cnt);
    for(int i=0; i < sz(rez); i+= 2){
        //Aage aur array hai tho that means there are other ones
        if(i+1 < sz(rez)){
            for(int j=0; j < rez[i]-1; j++)cout<<"0"<<" ";
            for(int j=0; j < rez[i+1]; j++)cout<<"0"<<" ";
            cout<<rez[i+1]<<" ";
        }
        else{
            for(int j=0; j < rez[i]; j++)cout<<"0"<<" ";
        }
        
    }
    cout<<nl;
}



    signed main() {
        
        ff();
        int tc;
        cin >> tc;
        // tc = 1;
        while (tc--) {
            // cout<<"#TEST CASE:"<<tc<<nl;
            solve();
        }
        return 0;
    }
