#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll, ll>>p(n);
        for(ll i = 0;i<n;i++){
            cin>>p[i].first>>p[i].second;
        }
        map<ll, ll>mp1; //x-y
        map<ll, ll>mp2; //x+y
        map<ll, ll>X; //x
        map<ll, ll>Y; //y
        for(ll i = 0;i<n;i++){
            ll val1 = p[i].first - p[i].second;
            ll val2 = p[i].first + p[i].second;
            mp1[val1]++;
            mp2[val2]++;
            X[p[i].first]++;
            Y[p[i].second]++;
        }
        ll ans = 0;
        for(auto it:mp1){
            ans += (it.second)*(it.second-1);
        }
        for(auto it:mp2){
            ans += (it.second)*(it.second-1);
        }
        for(auto it:X){
            ans += (it.second)*(it.second-1);
        }
        for(auto it:Y){
            ans += (it.second)*(it.second-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}