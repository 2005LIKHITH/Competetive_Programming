#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];

    set<int> st;
    st.insert(0);
    st.insert(n);

    multiset<int> lengths;
    lengths.insert(n);

    for(int i = 0; i < k; i++){
        int p = a[i];

        auto it_up = st.upper_bound(p);
        auto it_lb = prev(it_up);

        int right = *it_up;
        int left = *it_lb;

        lengths.erase(lengths.find(right - left));
        lengths.insert(right - p);
        lengths.insert(p - left);

        st.insert(p);

        cout << *lengths.rbegin() << " ";
    }
    cout << endl;
}
