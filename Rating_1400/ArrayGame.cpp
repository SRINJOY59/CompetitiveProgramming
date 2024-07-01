#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, s;
    cin >> n >> s;
    if (s / n <= 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        ll val = s / n;
        ll rem = s % n;
        ll sum = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            cout << val << " ";
            sum += val;
        }
        cout << s - sum << endl;
        cout << 1 << endl;
    }
    return 0;
}