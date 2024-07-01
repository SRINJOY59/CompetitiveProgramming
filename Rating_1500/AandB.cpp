#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll maxi = max(a, b);
        ll mini = min(a, b);
        ll diff = maxi - mini;
        ll low = 0;
        ll high = 1e5;
        ll ans = 0;
        vector<ll>values(high, 0);
        for(ll i = 0;i<high;i++){
            ll val = i;
            ll num = ((val+1)*val)/2;
            num = num - diff;
            if(num%2 == 0 && num >= 0){
                ans = val;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
