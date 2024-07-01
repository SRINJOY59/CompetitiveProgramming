#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<pair<ll, ll>, ll> p1, pair<pair<ll, ll>, ll> p2){
    if(p1.first.first == p2.first.first){
        return p1.first.second < p2.first.second;
    }
    return p1.first.first<p2.first.first;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<pair<ll, ll>, ll>>arr(n);
        for(ll i = 0;i<n;i++){
            cin>>arr[i].first.first>>arr[i].first.second;
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end(), cmp);
        ll cnt = 1;
        vector<ll>ans(n, 2);
        ans[arr[0].second] = 1;
        ll prev = arr[0].first.second;
        for(ll i = 1;i<n;i++){
            if(arr[i].first.first <= prev){
                ans[arr[i].second] = 1;
                prev = max(prev, arr[i].first.second);
                cnt++;
            }
            else{
                break;
            }
        }
        if(cnt == n){
            cout<<-1<<endl;
        }
        else{
            for(ll i = 0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}