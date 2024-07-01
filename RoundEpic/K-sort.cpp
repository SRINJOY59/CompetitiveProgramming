#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // vector<bool> vis(n, false);
        vector<ll> decreasing;
        ll maxi = arr[0];

        for (ll i = 1; i < n; i++) {
            if (arr[i] >= maxi) {
                maxi = arr[i];
            }
            else{
                decreasing.push_back(maxi - arr[i]);
            }
        }
        
        
        ll ans = 0;
        ll sz = decreasing.size();
        ll sum  = 0;
        sort(decreasing.begin(),decreasing.end());
        for(ll i = 0; i < decreasing.size(); i++) {
            ans += (sz - i + 1)*(decreasing[i] - sum);
            sum += decreasing[i] - sum;
        }
        cout << ans << endl;
    }
    return 0;
}
