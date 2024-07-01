#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        string str;
        cin >> str;
        // ll n = str.size();
        ll Acnt = 0;
        ll ans = 0;
        ll Bcnt = 0;
        for (ll i = 0; i < n - 1; i++) {
            if (str[i] == 'A') {
                Acnt++;
            }
            if (str[i] == 'A' && str[i + 1] == 'B') {
                ans += Acnt;
                swap(str[i], str[i + 1]);
                Acnt = 1;
                ll j = i + 2;
                while (j < n && str[j] != 'A') {
                    j++;
                    Bcnt++;
                }
                i = j - 1;
                ans += Bcnt;
                Bcnt = 0;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
