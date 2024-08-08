#include<bits/stdc++.h>
using namespace std;

int n;
int t[10001];
int s[10001];
int taken[100001];
int x,k;

bool check(int level){
    int timeTaken = 0;
    int itemTaken = 0;

    for(int i=0; i <= level; i++){
        if(taken[i]){
            timeTaken += t[i];
            itemTaken++;
        }
    }
    if(timeTaken <= x && itemTaken <= k)return true;
    return false;
}

int rec(int level){
    
    if(level == n)return 0;

    //ether you can pick a thing or not pick a thing 

    int ans = rec(level+1);

    if(check(level)){
        taken[level] = 1;
        ans = max(ans,s[level]+rec(level+1));
        taken[level] = 0;
    } 
}
void solve(){
    cin>>n;
    for(int i=0; i < n; i++)cin>>t[i]>>s[i];
    cin>>x>>k;
    memset(taken,0,sizeof(taken));
    cout<<rec(0)<<endl;
}
int main(){
    solve();
}