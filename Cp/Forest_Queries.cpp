//https://cses.fi/problemset/task/1652

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

int32_t main(){
    ff();
    int n,q;
    cin>>n>>q;
    vector<vector<int>>grid(n,vector<int>(n,0));
    for(int i=0; i < n; i++){
        for(int j= 0; j < n; j++){
            char t;
            cin>>t;
            if(t == '*')grid[i][j] = 1;
        }
    }
    vector<vector<int>>pre(n+1,vector<int>(n+1,0));

    for(int i=1 ; i <= n; i++){
        for(int j=1; j <= n; j++){
            pre[i][j] = grid[i-1][j- 1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]<<endl;
    }

}