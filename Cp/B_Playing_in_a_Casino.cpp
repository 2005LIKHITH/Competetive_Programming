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

// Don't Read the problem Statement LOLLLL

void solve(){
    // Constraints observation 10^6 definetly a O(n^2) Solution
    int r,c;
    cin>>r>>c;
    vector<int>arr[c];
    for(int i=0; i < r; i++){
        for(int j=0;  j < c; j++){
            int t;
            cin>>t;
            arr[j].push_back(t);
        }
    }
    int sum = 0;
    for(int i=0; i < c; i++){
        sort(all(arr[i]));
        vi suffix(r,0);
        suffix[r-1] = arr[i][r-1];
        for(int j=r-2; j >= 0; j--){
            suffix[j] = arr[i][j]+suffix[j+1];
        }
        for(int j=0; j < r-1; j++){
            sum += (suffix[j+1]-(r-j-1)*arr[i][j]);
        }

    }
    cout<<sum;
}

int32_t main(){
    ff();
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        cout<<endl;
    }
}