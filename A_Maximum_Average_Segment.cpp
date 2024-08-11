#include <bits/stdc++.h>
using namespace std;

#define ff() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define vi vector<int>
#define db long double
#define input(start, end, arr) { for(int i = start; i < end; ++i) cin >> arr[i]; }
#define nl '\n'

// Function to calculate the maximum subarray sum with at least 'd' elements
db maximumSum(vector<db>& arr, int d, int n) {
    vector<db> pref(n);
    pref[0] = arr[0];
    for(int i = 1; i < n; i++) {
        pref[i] = arr[i] + pref[i - 1];
    }
    
    db ans = -1e18;
    db mini = 0;
    for(int right = d - 1; right < n; right++) {
        db temp = pref[right] - mini;
        ans = max(ans, temp);
        mini = min(mini, pref[right - d + 1]);
    }
    return ans;
}

// Function to check if a given mean value is feasible
bool check(db mid, vector<db>& a, int n, int d) {
    vector<db> transformed(n);
    for(int i = 0; i < n; i++) {
        transformed[i] = a[i] - mid;
    }
    return maximumSum(transformed, d, n) >= 0;
}


pair<int, int> pairCheck(db mid, vector<db>& transformed, int n, int d) {
    vector<db> pref(n);
    pref[0] = transformed[0];
    for(int i = 1; i < n; i++) {
        pref[i] = transformed[i] + pref[i - 1];
    }
    
    db ans = -1e18;
    db mini = 0;
    int left = -1;
    int bestLeft = -1, bestRight = -1;
    for(int right = d - 1; right < n; right++) {
        db temp = pref[right] - mini;
        if(temp > ans) {
            ans = temp;
            bestLeft = left + 1;  
            bestRight = right;    
        }
        if(pref[right - d + 1] < mini) {
            mini = pref[right - d + 1];
            left = right - d + 1;  
    }
    return {bestLeft + 1, bestRight + 1};  


pair<int, int> findPair(db mid, vector<db>& a, int n, int d) {
    vector<db> transformed(a.begin(), a.end());
    for(auto &it : transformed) {
        it -= mid;
    }
    return pairCheck(mid, transformed, n, d);
}

void solve() {
    int n, d;
    cin >> n >> d;
    vector<db> a(n);
    input(0, n, a);
    
    db ans = -1;
    db l = 0;
    db h = 1e3;
    db eps = 1e-9;  // Precision level

    while (h - l > eps) {
        db mid = (l + h) / 2;
        if (check(mid, a, n, d)) {
            ans = mid;
            l = mid;  
        } else {
            h = mid;  
        }
    }

    // Now you have the best possible mean 
    pair<int, int> pairAns = findPair(ans, a, n, d);
    cout << pairAns.first << " " << pairAns.second << nl;
}

int32_t main() {
    ff();
    int tc;
    tc = 1;
    while(tc--) {
        solve();
    }
    return 0;
}
