#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<pair<ll, ll>>& p, ll n, ll k) {
    ll start = 0;
    ll right = 0;
    for (ll i = 0; i < n; i++) {
        start = max(start - k, p[i].first);
        right = min(right + k, p[i].second);
        if (start > right) {
            return false;
        }
    }
    return true;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> p(n);
        for (ll i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }
        ll left = 0;
        ll right = 1e12;
        ll ans = right;  

        while (left <= right) {
            ll mid = (left + right) / 2;
            if (check(p, n, mid)) {
                ans = mid; 
                right = mid - 1;  
            } else {
                left = mid + 1;  
            }
        }
        cout << ans << endl;
    }
    return 0;
}
