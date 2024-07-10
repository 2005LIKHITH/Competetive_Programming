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
#define  ppc         __builtin_popcount
#define  ppcll       __builtin_popcountll
#define pi (3.141592653589)

int check(vector<double> &c,int k){
    double long sum  = 0;
    for(int i=0; i < k; i++){
        sum += c[i];
    }
    return sum >= 0;
}

int32_t main(){
    int n,k;
    cin>>n>>k;
    vector<pair<double,double>>a(n,{0,0});
    for(int i=0; i < n; i++){
        int t,s;
        cin>>t>>s;
        a[i] = {t,s};
    }

    long double precision = 1e-10;
    long double l = precision;
    long double h = 1e18;
    long double ans = -1;

    int cnt = 0;
    while(h-l > precision){
        long double mid = (l+h)/2;
        vector<double> c(n);
        for(int i=0; i < n; i++){
            c[i] = a[i].first-mid*a[i].second;
        }
        sort(all(c));
        reverse(all(c));

        if(check(c,k)){
            ans = mid;
            l = mid+precision;
        }else h = mid-precision;
        cnt++;
        if(cnt > 500)break;
    }
    cout<<setprecision(12)<<fixed<<ans;

}