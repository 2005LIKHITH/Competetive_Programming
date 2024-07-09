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

void solve(){
    int n;
    cin>>n;
    vi a(n,0);
    input(0,n,a);
    sort(all(a));
    int left = 0;
    int right = n-1;
    vi diff;
    while(left <= right){
        if(left == right)diff.push_back(a[left]);
        else{
            diff.push_back(a[right]-a[left]);
        }
        left++;
        right--;
    }
    //now we got 7 3 3 3 1 => 6 0 3
}
int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}