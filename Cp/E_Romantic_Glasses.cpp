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
    // the main important thing to notice is theat they asked to output yes/no not the specific l and r
    // let us take one thing as negative so that when they become we weill get zero 
    // when they become zero the prefix sum repeats
    // Lmao when prefix sum repeats at some segment they are equal

    multiset<int>st;
    int preSum = 0;
    st.insert(preSum); //=>for edge case if everythign is cancelled then you will remanin with zero

    for(int i=0; i < n; i++){
        if(i&1)preSum -= a[i];
        else preSum += a[i];
        if(st.count(preSum) > 0){
            pyes
            return;
        }else st.insert(preSum);
    }
    pno;
}

int32_t main(){
    ff();
    int tc;
    cin>>tc;
    while(tc--){
w3        solve();
        cout<<endl;
    }
}