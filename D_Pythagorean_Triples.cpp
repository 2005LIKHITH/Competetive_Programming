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
#define INF 1e18
#define nline "\n"

// the question asks us to find there are how many tripletes where his formula and actual formula satisfies

void Likhith(){
    int n;
    cin>>n;
    /*
        a,b,c

        c^2 = b^2+a^2
        c = a^2 - b
        2b+1 = a^2

        how many pairs where these both conditoins are satisfied

        c2 = b2 + b +c
        (c+b)*(c-b) = c+b
        c= b+1

        b+1 = a2-b
        2b+1 = a2
        b = a^2-1/2
        c = a^2+1/2
        a = 3
        c = 5 b = 4

        a can only be odd 

        we have max c where 

        c2 = a2-b

 
    



    */
   //binary serach and check if c <= n 
   int l = 0;
   int h = n;
   int ans = 0;
   while(l <= h){
        int mid = (l+h)/2;
        int a = 2*mid+1;
        int c = (a*a+1)/2;
        if(c <= n){
            l = mid+1;
            ans = mid;
        }else h = mid-1;

   }
   cout<<ans;

}

int32_t main(){
    ff();
    int tc;
    cin>>tc;
    while(tc--){
        Likhith();
        cout<<nline;
    }
}