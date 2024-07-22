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
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nl '\n'

int32_t main(){
    ff();
    int n,k;
    cin>>n>>k;
    vi a(n,0);
    input(0,n,a);

    int ans = 0;
    int j = 0;
    int maxi = 0;
    int mini = 0;
    map<int,int>mp;
    for(int i=0; i < n; i++){
        mp[a[i]]++;
        maxi = mp.rbegin()->first;
        mini = mp.begin()->first;

        while(j <= i && maxi-mini > k){
            int el = a[j];
            mp[a[j]]--;
            if(mp[a[j]] == 0)mp.erase(a[j]);
            maxi = mp.rbegin()->first;
            mini = mp.begin()->first;
            j++;
        }
        ans += (i-j+1);
        
    }
    cout<<ans;
}