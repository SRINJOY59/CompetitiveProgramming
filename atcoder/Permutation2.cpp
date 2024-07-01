#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(m);
    
    for(ll i = 0; i < m; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    bool flag = true;
    for(ll i = 0; i < m; i++) {
        if(arr[i] == 1 || arr[i] == n) {
            flag = false;
            break;
        }
    }
    
    if(flag) {
        map<ll, ll>mp;
        for(ll i = 0; i < m; i++) {
            mp[arr[i]]++;
        }
        vector<ll>ans(n);
        iota(ans.begin(), ans.end(), 1);
        for(ll i = 1;i<n;i++){
            if(mp[i]){
                swap(ans[i-1], ans[i]);
            }
        }
        for(ll i = 0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    
    return 0;
}
