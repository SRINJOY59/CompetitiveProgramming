#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        ll xor_sum = 0;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            xor_sum ^= a[i];
        }

        cout << 2 << endl;
        ll ans = sum + xor_sum;
        cout << xor_sum << " " << ans << endl;
    }
    return 0;
}
