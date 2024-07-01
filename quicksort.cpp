#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        ll n,  k;
        cin >> n >> k;
        
        vector<ll> a(n);
        
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll count = 1;
        for(ll i = 0;i<n;i++){
            if(a[i] == count){
                count++;
            }
        }
        if(count == n+1){
            cout<<0<<endl;
        }
        else{
            ll val = n - count;
            ll ans = (val/k) + 1;
            cout<<ans<<endl;
        }
    }
    
    return 0;
}
