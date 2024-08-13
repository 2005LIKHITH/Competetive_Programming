#include <bits/stdc++.h>
using namespace std;

// Speed
#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Define
#define int long long int
#define vi vector<int>
#define pyes cout << "YES\n";
#define pno cout << "NO\n";

#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)
#define MOD1 998244353
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define sz(a) (int)a.size()

#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define pi (3.141592653589)
#define INF 1e18
#define nl '\n'
#define sp " "


int askQuery(int l, int h) {
    // if(h<=l){return -1;}
    cout << "? " << l << " " << h << endl;
    cout.flush();
    int query;
    cin >> query;
    return query;
}

void solve() {
    int n;
    cin >> n;
    
    int l = 1;
    int h = n;
    int f=0;
    while (l <= h) {
        int mid = (l + h) / 2;
        
        if(l==h){
            cout<<"! "<<l<<endl;
            return;
        }
         if(h == l+1){f=1;break;}
        int secondMax = askQuery(l, h);

        if (secondMax <= mid) {
            int temp = askQuery(l, mid);
            if (temp == secondMax) {
                h = mid;
            } else {
                l = mid;  
            }
        } else {
            int temp = askQuery(mid , h);
            if (temp == secondMax) {
                l = mid;  
            } else {
                h = mid;
            }
        }
    }
    if(f==0){
    cout << "! " << l << endl;
    }
    else{
         cout<<"? "<<l<<" "<<h<<endl;
           int possmax;
        cin>>possmax;
        if(possmax == l)
        {
            cout<<"! "<<h<<endl;
        }
        else
        {
            cout<<"! "<<l<<endl;
        }
    }
    }

int32_t main() {
    ff();
    solve();
    return 0;
}
