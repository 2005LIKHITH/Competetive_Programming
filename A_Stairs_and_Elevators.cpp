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
     
    void solve() {
                
        /*
            CRUX=> 
            find the nearest lift in left and finding the nearest lift in the right
            find the nearest elevator in left and find the nearest elevator in the right
            find the minimum distance
 
 
                we will use lower Bound / upper Bound stuff of for findingout the nearest things
        
        */
        int n, m, sC, eC, v;
        cin >> n >> m >> sC >> eC >> v;
        vi stairs(sC, 0);
        vi elevator(eC, 0);
        input(0, sC, stairs);
        input(0, eC, elevator);
        sort(all(stairs));
        sort(all(elevator));
        int q;
        cin >> q;
        while (q--) {
            int ans = 1e18;  // Use a large value for initialization
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
     
            if (x1 == x2) {  // If both rooms are on the same floor, no need to use stairs or elevator
                cout << abs(y1 - y2) << nl;
                continue;
            }
     
            int itr;
     
            // Nearest stair to the left and right
            if (sz(stairs)) {
                itr = lower_bound(all(stairs), y1) - stairs.begin();
                if (itr > 0) {
                    int temp1 = abs(y1 - stairs[itr - 1]);
                    int temp2 = abs(y2 - stairs[itr - 1]);
                    int temp3 = abs(x2 - x1);
                    ans = min(ans, temp1 + temp2 + temp3);
                }
                if (itr < sC) {
                    int temp1 = abs(y1 - stairs[itr]);
                    int temp2 = abs(y2 - stairs[itr]);
                    int temp3 = abs(x2 - x1);
                    ans = min(ans, temp1 + temp2 + temp3);
                }
            }
     
            // Nearest elevator to the left and right
            if (sz(elevator)) {
                itr = lower_bound(all(elevator), y1) - elevator.begin();
                if (itr > 0) {
                    int temp1 = abs(y1 - elevator[itr - 1]);
                    int temp2 = abs(y2 - elevator[itr - 1]);
                    int temp3 = abs(x2 - x1) / v + (abs(x2 - x1) % v != 0);
                    ans = min(ans, temp1 + temp2 + temp3);
                }
                if (itr < eC) {
                    int temp1 = abs(y1 - elevator[itr]);
                    int temp2 = abs(y2 - elevator[itr]);
                    int temp3 = abs(x2 - x1) / v + (abs(x2 - x1) % v != 0);
                    ans = min(ans, temp1 + temp2 + temp3);
                }
            }
     
            cout << ans << nl;
        }
    }
     
     
    int32_t main() {
        ff();
        int tc;
        tc = 1;
        while (tc--) {
            solve();
        }
        return 0;
    }

