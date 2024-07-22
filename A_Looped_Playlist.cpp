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
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
// 3 1 1 1 4
// 3 1 1 1 4 3 1 1 1 4


//Approach is binary search plus fixed size sliding window 

pair<int,int>check(int mid,int n,int k,vi &a){
    pair<int,int>res = {-1,-1};
    int sum = 0;
    for(int i=0; i < n; i++){
        sum += a[i];
        if(i >= k){
            sum -= a[i-k];
        }
        if(i >= k-1 && sum >= k){
            res.first = i-k;
            res.second = mid;
        }
    }
    return res;
}

int32_t main(){
    int n,k;
    cin>>n>>k;
    vi a(n,0);
    input(0,n,a);

    for(auto it: a){
        a.push_back(it);
    }
    n = sz(a);
    int l = 0;
    int h = n;
    pair<int,int>ans;
    while(l <= h){
        int mid = (l+h)/2;
        pair<int,int> temp = check(mid,n,k,a);
        if(temp.first != -1){
            l = mid+1;
        }else{
            ans.first = temp.first;
            ans.second = temp.second;
            h = mid-1;
        }
    }
    cout<<ans.first<<" "<<ans.second;
}