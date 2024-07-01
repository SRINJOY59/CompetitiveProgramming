#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        map<ll, ll> mp;
        vector<ll> counts;
        
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            mp[arr[i]]++;
        }
        
        for(auto it : mp){
            counts.push_back(it.second);
        }
        
        sort(counts.begin(), counts.end(), greater<ll>());
        
        ll ans = counts[0];
        ll prev = counts[0];
        
        for(ll i = 1; i < counts.size() && prev > 0; i++){
            if(counts[i] >= prev){
                ans += prev - 1;
                prev -= 1;
            } else {
                ans += counts[i];
                prev = counts[i];
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}
