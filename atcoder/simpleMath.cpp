#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int last_digit_of_power_of_2(ll N) {

    if (N == 0) return 1; // 2^0 = 1
    int cycle[] = {6, 2, 4, 8};
    return cycle[N % 4];
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll N, M, K;
        cin >> N >> M >> K;
        
        ll cycle_length = M - K;
        
        if (N >= M) {
            N = N % cycle_length + cycle_length;
            if (N >= M) {
                N -= cycle_length;
            }
        }

        if (N == M - 1 && K == M - 1) {
            cout << 0 << endl;
        } else {
            cout << last_digit_of_power_of_2(N) << endl;
        }
    }
    return 0;
}
