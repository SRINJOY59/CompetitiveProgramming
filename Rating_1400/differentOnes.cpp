#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n + 1);
        for(ll i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        vector<ll> checker(n, -1);
        for(ll i = 1; i < n; i++) {
            if(arr[i] != arr[i + 1]) {
                checker[i] = 1;
            }
        }

        vector<ll> prefix(n + 1, 0);
        ll count = 0;
        for(ll i = 1; i < n; i++) {
            if(checker[i] == 1) {
                count += 1;
            }
            prefix[i] = count;
        }

        ll q;
        cin >> q;
        while(q--) {
            ll l, r;
            cin >> l >> r;
            
            if (l == r) {
                cout << -1 << " " << -1 << endl;
                continue;
            }

            ll val = prefix[r - 1] - prefix[l - 1];
            if(val >= 1) {
                ll upper = upper_bound(prefix.begin() + l, prefix.begin() + r, prefix[l - 1]) - prefix.begin();
                cout << upper << " " << upper + 1 << endl;
            } else {
                cout << -1 << " " << -1 << endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
