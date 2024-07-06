#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n, k, x;
    cin >> n >> k >> x;  
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (ll i = 0; i < n; i++) {
        cout << arr[i] << " ";
        if (i == k - 1) {  
            cout << x << " ";  
        }
    }
    cout<<endl;
    return 0;
}

