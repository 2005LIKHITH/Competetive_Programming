#include <iostream>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;
        
        int cnt = 0;
        
        while (n--) {
            int x, y;
            cin >> x >> y;
            
            if (y == 1) {
                cnt++;
            }
        }
        
        cout << cnt * 2 << endl;
    }
    
    return 0;
}
