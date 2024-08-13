#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
      int n,response;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++)cin>>a[i];

      int pre[n];
      pre[0]=a[0];
      for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
      }

      int start=0,end=n-1;
      int ans=-1;
      while(start<=end){
        int mid=start+(end-start)/2;

        cout<<"? "<<(mid-start+1)<<" ";
        for(int i=start;i<=mid;i++){
          cout<<i+1<<" ";
        }
        cout<<endl;
        cout.flush();
        cin>>response;
        if(response>pre[mid]-(start==0 ? 0 : pre[start-1] )){
          ans=mid;
          end=mid-1;
        }
        else{
          start=mid+1;
        }
      }
      cout<<"! "<<ans+1<<endl<<flush;

    }

}