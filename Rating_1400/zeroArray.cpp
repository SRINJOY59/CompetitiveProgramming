#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    if (sum & 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        ll maxi = *max_element(arr.begin(), arr.end());
        if (sum - maxi >= maxi)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}