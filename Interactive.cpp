#include <bits/stdc++.h>
using namespace std;


int main(){
    int l = 0;
    int r = 100;
    int ans = -1;
    while(l <= r){
        int m = (l+r)/2;
        cout<<" ? "<< m <<endl;

        char response;
        cin>>response;
        if(response == '=')ans = m;break;
        if(response == '<')l = m+1;
        else r = m-1;
    }
    cout<<"!"<<ans<<endl;
    return 0;
}