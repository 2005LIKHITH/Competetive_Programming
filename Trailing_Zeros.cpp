#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    int n;
    cin>>n;
    int cnt = 0;
    
    for(int i=0; i < 32; i++){
        if(((n) & (1 << i)) == 0){
            cnt++;
        }else break;
    }
    cout<<cnt<<endl;
}