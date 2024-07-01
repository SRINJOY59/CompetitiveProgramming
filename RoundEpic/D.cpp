#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;

                if (len == 1) {
                    dp[i][j] = 1;
                } else {
                    int alicePickLeft = a[i] > (i > 0 ? a[i - 1] : -1) ? 1 : 0;
                    int alicePickRight = a[j] > a[j - 1] ? 1 : 0;
                    
                    dp[i][j] = max(
                        alicePickLeft + (a[i] > (i > 0 ? a[i - 1] : -1) ? dp[i + 1][j] : 0),
                        alicePickRight + (a[j] > a[j - 1] ? dp[i][j - 1] : 0)
                    );
                }
            }
        }
        
        cout << dp[0][n - 1] << endl;
    }
    
    return 0;
}


