#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        
        vector<ll> a(n);
        ll onecount = 0;
        ll sum = 0;
        
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                onecount++;
            }
            sum += a[i];
        }
        
        if (n == 1) {
            cout << "NO" << endl;
            continue;
        }
        if(n == onecount){
            cout<<"NO" << endl;
            continue;
        }
        ll nVal = 2 * onecount;
        ll remainder = sum - nVal;
        
        ll div = remainder / (n - onecount);
        
        if (div >= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
