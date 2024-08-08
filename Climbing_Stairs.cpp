#include<bits/stdc++.h>
using namespace std;

int n,m;
int dp[1000001];

int rec(int level){
    if(level > n)return 1e9;
    if(level == n)return 0;
    if(dp[level] != -1)return dp[level];

    //choices

    int t= 1+rec(level+1);
    int s = 1+rec(level+m);

    return dp[level] = min(t,s);


}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    cout<<rec(0)<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    
    while(tc--)solve();
}