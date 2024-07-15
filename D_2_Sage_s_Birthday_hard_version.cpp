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
#define priority_queue<pii, vector<pii>, greater<pii>> minpq;
#define priority_queue<pii> maxpq;
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int) a.size()
#define  ppc         __builtin_popcount
#define  ppcll       __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nline "\n"


int check(int mid,vi &a,int n){
    // 1 3 2 2 4 5 4
    // 1 2 2 3 4 4 5
    //two pointer  1 < a[n-1] && 1 < a[n-2]

    int j = n-1;
    for(int i=mid-1; i >=0; i--){
        if(!(a[i] < a[j] && a[i] < a[j-1] && j > mid))return false;
        j--;
    }
    return true;

}
int32_t main(){
    int n;
    cin>>n;
    int maxVal = (n+1)/2-1;
    // cout<<maxVal<<nline; 
    vi a(n);
    input(0,n,a);
    int l = 0;
    int h = maxVal;
    int ans = 0;
    sort(all(a));
    while(l <= h){
        int mid = (l+h)/2;
        
        if(check(mid,a,n))l = mid+1,ans = mid;
        else h = mid-1;
    }
    // we will get the required ans
    // so letes form the array
    cout<<ans<<nline;

	vector<int>brr(n);
	int i=n-1,j=ans-1;
	
	for(int k=0;k<n;k++){
		if(k%2==0 || j==-1)brr[k]=a[i--];
		else brr[k]=a[j--];
	}
	
	for(auto it:brr)cout<<it<<" ";cout<<endl;
}