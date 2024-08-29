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
int query(int x,int y) {
    cout<<"? "<<x<<" "<<y<<endl;
    int res;
    cin>>res;
    return res;

}

void solve()
{
    int n,m;
    cin>>n>>m;
    int res=query(1,1);
    int res2=0,res3=0;
    int x2=0,y2=0,x3=0,y3=0;
    if(res<=n-1){
        x2=res+1;
        y2=1;
        res2=query(res+1,1);
    }
    else{
        x2=n;
        y2=res-n+2;
        res2=query(n,res-n+2);
    }
    if(res<=m-1){
        x3=1;
        y3=res+1;
        res3=query(1,res+1);
    }
    else{
        x3=res-m+2;
        y3=m;
        res3=query(res-m+2,m);
    }
    x3+=(res3/2);
    y3-=(res3/2);
    x2-=(res2/2);
    y2+=(res2/2);
    int res4=query(x3,y3);
    if(res4==0){
        cout<<"! "<<x3<<" "<<y3<<endl;
    }
    else{
        cout<<"! "<<x2<<" "<<y2<<endl;
    }
}


int32_t main() {
    ff();
    int tc;
    tc = 1;
    cin>>tc;
    
    while (tc--) {
        solve();
    }
    return 0;
}
