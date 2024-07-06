#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, c, d, e, f;
    ll g, h, i, j, k, l;

    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;
    
    ll minX1 = min(a, d), maxX1 = max(a, d);
    ll minY1 = min(b, e), maxY1 = max(b, e);
    ll minZ1 = min(c, f), maxZ1 = max(c, f);
    
    ll minX2 = min(g, j), maxX2 = max(g, j);
    ll minY2 = min(h, k), maxY2 = max(h, k);
    ll minZ2 = min(i, l), maxZ2 = max(i, l);
    
    bool overlapX = max(minX1, minX2) < min(maxX1, maxX2);
    bool overlapY = max(minY1, minY2) < min(maxY1, maxY2);
    bool overlapZ = max(minZ1, minZ2) < min(maxZ1, maxZ2);
    
    if (overlapX && overlapY && overlapZ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
