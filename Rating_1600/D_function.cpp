#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll bin_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;  
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        base = (base * base) % mod;  
        exp /= 2;
    }
    return result;
}

int main() {
    ll t;
    cin >> t;
    const ll mod = 1e9+7;  
    while (t--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll singleNum = (9 / k) + 1;
        ll ans = (bin_pow(singleNum, r, mod) - bin_pow(singleNum, l, mod) + mod) % mod;  
        cout << ans << endl;
    }
    return 0;
}
