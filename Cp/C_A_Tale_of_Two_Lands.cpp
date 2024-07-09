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


int32_t main(){
    ff();
    int n;
    cin>>n;
    vi a(n,0);
    for(int i=0; i < n; i++){
        int t;
        cin>>t;
        a[i] = abs(t);
    }
    sort(all(a));
    // int cnt = 0;
    // for(int i=0; i < n; i++){
    //     for(int j=i+1; j < n; j++){//2 3 5
    //         int x = a[i];
    //         int y = a[j];
    //         if(2*x >= y)cnt++;
    //         else break;
    //     }
    // }
    // cout<<cnt;
    // here to change this o(n^2) Solution what we can do it just keep one value constant in o(n) and search
    //for the suitable one in o(logn)

    int cnt = 0;
    for(int i=0; i < n; i++){
        int l = 0;
        int h = n-1;
        int ans = 0;
        int x = a[i];
        while(l <= h){
            int mid = (l+h)/2;
            int y = a[mid];
            if(2*x >= y)l = mid+1;
            else h = mid-1;
        }
        ans = l-i-1;
        cnt += ans;
    }
    cout<<cnt;
}