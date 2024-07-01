#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> arr(n, vector<ll>(m));
        for (ll i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (ll j = 0; j < m; j++) {
                arr[i][j] = s[j] - '0';
            }
        }
        ll ans = 0;
        vector<vector<ll>> result;

        for (ll i = 0; i < n - 1; i++) {
            for (ll j = 0; j < m - 1; j++) {
                vector<pair<ll, ll>> positions = {{i, j}, {i, j+1}, {i+1, j}, {i+1, j+1}};
                ll one_count = 0;
                for (auto& pos : positions) {
                    if (arr[pos.first][pos.second] == 1) {
                        one_count++;
                    }
                }
                
                if (one_count == 4) {
                    result.push_back({i+1, j+1, i+1, j+2, i+2, j+1});
                    result.push_back({i+1, j+2, i+2, j+1, i+2, j+2});
                    result.push_back({i+1, j+1, i+2, j+1, i+2, j+2});
                    result.push_back({i+1, j+1, i+1, j+2, i+2, j+2});
                    ans += 4;
                } else if (one_count == 3) {
                    vector<pair<ll, ll>> ones;
                    pair<ll, ll> zero;
                    for (auto& pos : positions) {
                        if (arr[pos.first][pos.second] == 1) {
                            ones.push_back(pos);
                        } else {
                            zero = pos;
                        }
                    }
                    result.push_back({ones[0].first+1, ones[0].second+1, ones[1].first+1, ones[1].second+1, ones[2].first+1, ones[2].second+1});
                    // result.push_back({ones[0].first+1, ones[0].second+1, ones[1].first+1, ones[1].second+1, zero.first+1, zero.second+1});
                    ans += 1;
                } else if (one_count == 2) {
                    vector<pair<ll, ll>> ones, zeros;
                    for (auto& pos : positions) {
                        if (arr[pos.first][pos.second] == 1) {
                            ones.push_back(pos);
                        } else {
                            zeros.push_back(pos);
                        }
                    }
                    result.push_back({ones[0].first+1, ones[0].second+1, zeros[0].first+1, zeros[0].second+1, zeros[1].first+1, zeros[1].second+1});
                    result.push_back({ones[1].first+1, ones[1].second+1, zeros[0].first+1, zeros[0].second+1, zeros[1].first+1, zeros[1].second+1});
                    ans += 2;
                } else if (one_count == 1) {
                    pair<ll, ll> one;
                    vector<pair<ll, ll>> zeros;
                    for (auto& pos : positions) {
                        if (arr[pos.first][pos.second] == 1) {
                            one = pos;
                        } else {
                            zeros.push_back(pos);
                        }
                    }
                    result.push_back({one.first+1, one.second+1, zeros[0].first+1, zeros[0].second+1, zeros[1].first+1, zeros[1].second+1});
                    result.push_back({one.first+1, one.second+1, zeros[1].first+1, zeros[1].second+1, zeros[2].first+1, zeros[2].second+1});
                    result.push_back({one.first+1, one.second+1, zeros[0].first+1, zeros[0].second+1, zeros[2].first+1, zeros[2].second+1});
                    ans += 3;
                }

                
                for (auto& pos : positions) {
                    arr[pos.first][pos.second] = 0;
                }
            }
        }

       
        cout << ans << endl;
        for (auto& res : result) {
            for (auto& val : res) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}