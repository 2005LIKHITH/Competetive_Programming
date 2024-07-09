#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pyes cout << "YES";
#define pno cout << "NO";
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod (ll)(1e9 + 7)

int solve(int n){
    return (n*(n+1))/2;
}

int32_t main(){
    ff();
    int n,k;
    cin>>n>>k;
    // int t = (k-1*(k-1))/2;
    n--;
    int t = solve(k-1);
    if(t < n){
        cout<<-1;
        return 0;
    }

    int l = 0;
    int h = k-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(t-solve(mid) >= n)l = mid+1;
        else h = mid-1;
    }
    cout<<k-1-h;
}