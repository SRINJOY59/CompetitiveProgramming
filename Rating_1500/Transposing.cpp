#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> M1(n, vector<ll>(m));
    vector<vector<ll>> M2(n, vector<ll>(m));
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> M1[i][j];
        }
    }
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> M2[i][j];
        }
    }
    
    bool flag = true;
    
    for (ll x = 0; x < n; x++) {
        vector<ll> a, b;
        for (ll i = x, j = 0; i >= 0 && j < m; i--, j++) {
            a.push_back(M1[i][j]);
            b.push_back(M2[i][j]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) {
            flag = false;
            break;
        }
    }
    
    if (flag) {
        for (ll y = 1; y < m; y++) {
            vector<ll> a, b;
            for (ll i = n - 1, j = y; i >= 0 && j < m; i--, j++) {
                a.push_back(M1[i][j]);
                b.push_back(M2[i][j]);
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if (a != b) {
                flag = false;
                break;
            }
        }
    }
    
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
