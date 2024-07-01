#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll bin_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long minStepsToPerfectSquare(long long n) {
    if (n < 0) return -1; 
    
    long long root = static_cast<long long>(sqrt(n));
    long long lowerSquare = root * root;
    long long upperSquare = (root + 1) * (root + 1);

    if (lowerSquare == n) {
        return 0; 
    }

    long long stepsToLower = n - lowerSquare;
    long long stepsToUpper = upperSquare - n;

    return min(stepsToLower, stepsToUpper);
}


int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll squares = 0;
    ll non_squares = 0;
    vector<ll>SQ;
    vector<ll>NSQ;
    for(ll i = 0;i<n;i++){
        ll val = sqrt(arr[i]);
        ll sqr = val*val;
        if(sqr == arr[i]){
            squares++;
            SQ.push_back(arr[i]);
        }
        else{
            non_squares++;
            NSQ.push_back(arr[i]);
        }
    }
    if(squares == non_squares){
        cout<<0<<endl;
    }
    else if(squares > non_squares){
        sort(SQ.begin(), SQ.end());
        // cout<<squares<<" "<<non_squares<<endl;
        ll diff = (squares - non_squares)/2;
        // cout<<diff<<endl;
        ll cost = 0;
        for(ll i = SQ.size()-1;i>=0;i--){
            if(SQ[i] != 0){
                cost += 1;
            }
            else{
                cost += 2;
            }
            diff--;
            if(diff == 0){
                break;
            }
        }
        cout<<cost<<endl;
    }
    else{
        ll diff = (non_squares - squares)/2;
        vector<ll>steps;
        for(ll i = 0;i<NSQ.size();i++){
            ll ans = minStepsToPerfectSquare(NSQ[i]);
            // cout<<ans<<" "<<NSQ[i]<<endl;
            steps.push_back(ans);
        }
        sort(steps.begin(), steps.end());
        ll cost = 0;
        for(ll i = 0;i<steps.size();i++){
            cost += steps[i];
            diff--;
            if(diff == 0){
                break;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}

