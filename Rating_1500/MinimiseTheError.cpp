#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct cmp {
    bool operator()(pair<ll, ll> p1, pair<ll, ll> p2) {
        return abs(p1.first - p1.second) < abs(p2.first - p2.second);
    }
};

int main() {
    ll n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    for (ll i = 0; i < n; i++) {
        pq.push(make_pair(a[i], b[i]));
    }

    ll totalOperations = k1 + k2;
    while (totalOperations > 0) {
        pair<ll, ll> p = pq.top();
        pq.pop();
        ll a = p.first;
        ll b = p.second;
        
        if (abs(a - b) == 0) {
            a++; 
            k1--;
        } else if (a > b) {
            if (k1 > 0) {
                a--;
                k1--;
            } else {
                b++;
                k2--;
            }
        } else {
            if (k2 > 0) {
                b--;
                k2--;
            } else {
                a++;
                k1--;
            }
        }
        totalOperations--;
        
        pq.push(make_pair(a, b));
    }

    ll ans = 0;
    while (!pq.empty()) {
        pair<ll, ll> p = pq.top();
        pq.pop();
        ans += (p.first - p.second) * (p.first - p.second);
    }

    cout << ans << endl;
    return 0;
}
