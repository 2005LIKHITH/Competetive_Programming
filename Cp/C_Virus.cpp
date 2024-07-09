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
    int n,m;
    cin>>n>>m;
    vi a(m,0);
    input(0,m,a);
    sort(all(a));
    // we to find the maximum block and protect it let us take 41 5
    // 1 11 21 31 41 
    // sort the differences and try to sort them kind of approach..
    // for every thing we shoudl block form two sides at the end in the block we will only have 9-1
    // then we should take care of moves
    vi diff;
    for(int i=1; i < m; i++){
        diff.push_back(a[i]-a[i-1]-1);
    }
    //to make cyclic 
    // diff.push_back(a[m-1]-a[0]-1);
    diff.push_back(a[0]+n-1-a[m-1]);
    // sort(all(diff));
    // reverse(all(diff));
    sort(all(diff),greater<int>());
    int moves = 0;
    int safe = 0;
    for(int i = 0; i < diff.size(); i++){
        int curr = diff[i]-(2*moves);
        if(curr <= 0)break; //aage jaane ka koi matlab nahi hain bcz the diff array is sorted
        safe+=curr-1;
        moves += 2;
        //if we have diff as 1 then we will save it right
        if(curr == 1)safe++;

    }
    cout<<n-safe;

    
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