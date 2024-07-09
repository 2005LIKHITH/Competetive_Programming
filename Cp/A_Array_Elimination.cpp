// Jai Shree Ram 
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define mod (int)(1e9 + 7)
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define priority_queue<pii, vector<pii>, greater<pii>> minpq;
#define priority_queue<pii> maxpq;
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define  ppc   __builtin_popcount
#define  ppcll   __builtin_popcountll
#define pi (3.141592653589)
#define PI 3.1415926535897932384626433832795



void solve(){
        int n;
        cin >> n;
        vi arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        vector<int> validK(n + 1, 1);

        
        for(int i = 0; i < 30; i++){
            vector<int> validFactors(n + 1);

            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(arr[j] & (1 << i)){
                    cnt++;
                }
            }
            for(int j = 1; j <= n; j++){
                if(cnt % j == 0){
                    validFactors[j] = 1;
                }
            }
            for(int j = 1; j <= n; j++){
                validK[j] = validK[j] & validFactors[j];
            }
        }
        for(int i = 1; i <= n; i++){
            if(validK[i]){
                cout << i << " ";
            }
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