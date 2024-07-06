#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    if (K == 0) {
        cout << (*max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end())) << endl;
        return 0;
    }
    
    if (K == N) {
        cout << 0 << endl;
        return 0;
    }
    
    sort(A.begin(), A.end());
    
    ll min_diff = LLONG_MAX;
    
    for (ll i = 0; i <= N - K; ++i) {
        ll current_diff = A[i + N - K - 1] - A[i];
        min_diff = min(min_diff, current_diff);
    }
    
    cout << min_diff << endl;
    
    return 0;
}

