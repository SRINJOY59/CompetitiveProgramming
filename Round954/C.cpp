#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        string c;
        vector<ll>updates(m);
        for(ll i = 0;i<m;i++){
            cin>>updates[i];
        }
        cin>>c;
        set<ll>S;
        for(ll i = 0;i<m;i++){
            S.insert(updates[i]);
        }
        vector<ll>set_indexes;
        for(auto it:S){
            set_indexes.push_back(it);
        }
        sort(c.begin(), c.end());
        map<ll, char>mp;
        for(ll i = 0;i<set_indexes.size();i++){
            mp[set_indexes[i]] = c[i];
        }
        for(auto it:mp){
            ll index = it.first - 1;
            s[index] = it.second;
        }
        cout<<s<<endl;
    }
    return 0;
}
