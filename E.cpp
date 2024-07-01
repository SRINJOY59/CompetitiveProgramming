#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> values; 
    unordered_map<ll, ll> seen; 

    ll start = x;
    ll sum = 0;
    ll cycle_start = -1;
    ll cycle_length = 0;


    for (ll i = 0; i < n; ++i) {
        if (seen.find(start) != seen.end()) {
            cycle_start = seen[start];
            cycle_length = i - cycle_start;
            break;
        }
        seen[start] = i;
        values.push_back(start);
        sum += start;
        start = (start * start) % m;
    }

    if (cycle_start == -1) {

        cout << sum << endl;
        return 0;
    }


    ll pre_cycle_sum = 0;
    for (ll i = 0; i < cycle_start; ++i) {
        pre_cycle_sum += values[i];
    }


    ll cycle_sum = 0;
    for (ll i = cycle_start; i < cycle_start + cycle_length; ++i) {
        cycle_sum += values[i];
    }


    ll full_cycles = (n - cycle_start) / cycle_length;
    ll remaining_elements = (n - cycle_start) % cycle_length;


    ll total_sum = pre_cycle_sum + full_cycles * cycle_sum;
    for (ll i = 0; i < remaining_elements; ++i) {
        total_sum += values[cycle_start + i];
    }

    cout << total_sum << endl;
    return 0;
}
