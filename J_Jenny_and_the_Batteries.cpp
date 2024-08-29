#include<bits/stdc++.h>
using namespace std;

#define int long long

struct compare {
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[0] > b[0];
    }
};

bool check(vector<vector<int>> &arr, int mid, int k) {
    int cost = 0;
    int count = 0;
    int n = arr.size();
    priority_queue<vector<int>, vector<vector<int>>, compare> queue;
    for(int i=0;i<n;i++) {
        if(arr[i][0] > mid) {
            cost += arr[i][1] * (arr[i][0] - mid);
            count += arr[i][0] - mid;
        }
        else queue.push({arr[i][2], mid - arr[i][0]});
    }
    while(count > 0) {
        vector<int> p = queue.top();
        queue.pop();
        if(count <= p[1]) {
            cost += count * p[0];
            break;
        }
        else {
            cost += p[1] * p[0];
            count -= p[1];
        }
    }
    return cost <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int mx = 0;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sum += a;
        mx = max(mx, a);
        arr.push_back({a, b, c});
    }
    int start = (sum + n - 1) / n;
    int end = mx;
    int ans = end;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(check(arr, mid, k)) {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else start = mid + 1;
    }
    cout << ans << "\n";
}

signed main () {
    solve();
}