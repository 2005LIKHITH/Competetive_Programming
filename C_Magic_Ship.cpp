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
#define pi (3.141592653589)
#define INF 1e18
#define nline "\n"


//Will it be my first 1900 rated Question Lets Go

bool check(int mid,pair<int,int>initial,pair<int,int>final,string s){
    //Think greedily
}

int32_t main(){
    pair<int,int>initial;
    pair<int,int>final;
    cin>>initial.first>>initial.second>>final.first>>final.second;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l = 0;
    int h = 1e18;
    int ans;
    while(l <= h){
        int mid = (l+h)/2;
        if(check(mid,initial,final,s))h=mid-1,ans = mid;
        else l = mid+1;
    }
    cout<<ans<<nline;
}