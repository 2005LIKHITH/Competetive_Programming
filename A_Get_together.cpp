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


/*
    Learning Points 
    
    Convex Hull ===> Ternary Search          \_/  

    Some good implementation which should be remembered

    We cannot apply binary serach on the distance because it is giving convex hull like results
    that mean 
    it is not monotonic predicate it is just predicate

                FFFFFFTTTTTTFFFFFF

    we can apply binary search on time because it is a monotonic predicate function

    => Now here comes the main question how we can find are the ranges overlapping 
    for the given time 


    **** It includes binary search on decimals becuase they are also possible

*/


bool check(double mid,int n,vector<pair<double,double>>&a){
    //Here comes the main part comes which i should learn
    pair<double,double>curr = {-1e18,1e18};
    for(auto it:a){
        double pos = it.first;
        double speed = it.second;
        pair<double,double> range = {(pos-(speed*mid)),(pos+(speed*mid))};
        curr = {max(range.first,curr.first),min(range.second,curr.second)};
       
    }
     return curr.first <= curr.second;

}
int32_t main(){
    int n;
    cin>>n;
    vector<pair<double,double>>a(n,{0,0});
    for(int i=0; i < n; i++){
        double s,t;
        cin>>s>>t;
        a[i] = {s,t};
    }
    long double precision = 1e-8;
    long double l = 0;
    long double h = 1e18;
    long double ans = -1;

    int cnt  =0;
    while(h-l > precision){
        double mid = l+(h-l)/2;
        if(check(mid,n,a)){
            ans = mid;
            h = mid-precision;
        }else l = mid+precision;

        if(cnt > 500){
            break;
        }
        cnt++;//due to fault in c++ double we are doing this
    }
    cout<<setprecision(8)<<fixed<<ans;

}