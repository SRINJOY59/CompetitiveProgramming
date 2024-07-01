#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> M(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> M[i][j];

        vector<vector<ll>> updatedM = M;

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                bool flag = true;


                if (j - 1 >= 0 && M[i][j] <= M[i][j - 1]) flag = false;
                if (i - 1 >= 0 && M[i][j] <= M[i - 1][j]) flag = false;
                if (j + 1 < m && M[i][j] <= M[i][j + 1]) flag = false;
                if (i + 1 < n && M[i][j] <= M[i + 1][j]) flag = false;


                if (flag) {
                    ll maxi = LLONG_MIN;
                    if (j - 1 >= 0) maxi = max(maxi, M[i][j - 1]);
                    if (i - 1 >= 0) maxi = max(maxi, M[i - 1][j]);
                    if (j + 1 < m) maxi = max(maxi, M[i][j + 1]);
                    if (i + 1 < n) maxi = max(maxi, M[i + 1][j]);


                    updatedM[i][j] = maxi;
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << updatedM[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}


