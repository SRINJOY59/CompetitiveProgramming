#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, x;
        cin>>n>>x;
        vector<ll>a(n);
        vector<ll>b(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0; i<n; i++){
            cin>>b[i];
        }
        vector<ll>temp = b;
        vector<pair<ll, ll>> p(n);
        for(ll i = 0;i<n;i++){
            p.push_back({a[i], i});
        }
        sort(p.begin(), p.end());
        sort(b.begin(), b.end());
        ll aInd = 0;
        ll bInd = 0;
        bool flag = false;
        ll count = 0;
        vector<pair<ll, ll>>indices;
        while(aInd < n){
            if(p[aInd].first > b[bInd]){
                count++;
                indices.push_back({b[bInd], p[aInd].second});
                aInd++;
                bInd++;
            }
            else if(p[aInd].first < b[bInd]){
                aInd++;
            }
            else if(p[aInd].first == b[bInd]){
                aInd++;
                bInd++;
            }
            if(count == x){
                flag = true;
            }
        }
        if(flag){
            
        }
    }
}