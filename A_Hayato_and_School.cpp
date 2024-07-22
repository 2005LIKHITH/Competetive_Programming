#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)
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

int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

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
    bitset<8>b(n);
    return b.to_string();
}

bool check(int mid, int n, int k, vi &a) {
    int operations = k;
    for(int i=n-1; i >= 0; i--){
        if(operations > 0){
            if(a[i] <= a[i+1]){
                a[i] = a[i+1]+1;
                operations -= (a[i+1]-a[i]+1);//5 2
                                                //4 3 2 2 2
            }
        }
        else return (*(max_element(all(a))) >= mid);
    }
    return (*(max_element(all(a))) >= mid);
}

void solve(){
    int n;
    cin>>n;
    vi a(n,0);
    input(0,n,a);

    // for(int i=0; i < n; i++){
    //     for(int j=0; j < n; j++){
    //         for(int k=0; k < n; k++){
    //             if(i != j && j != k && k != i){
    //                 int sum = a[i]+a[j]+a[k];
    //                 if(sum & 1){
    //                     pyes
    //                     cout<<nl;
    //                     cout<<i+1<<" "<<j+1<<" "<<k+1;
    //                     return;
    //                 }
    //             }
    //         }
    //     }
    // }
    // pno

    // Cannot Brute force out

    // Odd number => 3 odd number 1 odd number and 2 even number

    vi odd;
    vi even;

    f(i,0,n){
        if(a[i] & 1)odd.push_back(i+1);
        else even.push_back(i+1);
    }
    if(sz(odd) == 0){
        pno
        return;
    }
    else if(sz(even) >= 2){
        pyes
        cout<<nl;
        cout<<even[0]<<" "<<even[1]<<" "<<odd[0];
    }
    else if(sz(odd) >= 3){
        pyes
        cout<<nl;
        cout<<odd[0]<<" "<<odd[1]<<" "<<odd[2];

    }
    else {
        pno
        
    }
}

int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}