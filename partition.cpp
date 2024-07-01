#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> countWays;

void precomputeCountWays(int maxN) {
    countWays.resize(maxN + 1, 0);

    for (int x = 1; x <= maxN; ++x) {
        for (int y = x; y <= maxN; y += x) {
            countWays[y]++;
        }
    }
}

int main() {
    int N;
    cin >> N;

    precomputeCountWays(N);

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += countWays[N - i];
    }
    
    cout << ans << endl;
    return 0;
}
