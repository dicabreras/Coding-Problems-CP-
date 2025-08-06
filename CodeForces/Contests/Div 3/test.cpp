#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> result;
        
        // Check odd digits 1, 3, 5, 7, 9
        for (int odd_digit : {1, 3, 5, 7, 9}) {
            if (d % odd_digit == 0) {
                result.push_back(odd_digit);
            }
        }
        
        // Print result
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
