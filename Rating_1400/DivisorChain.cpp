#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        ll msb = 31 - __builtin_clz(x);
        vector<ll>ans;
        ans.push_back(x);
        for(ll i = 0;i<msb;i++){
            if(x&(1<<i)){
                x -= (1<<i);
                ans.push_back(x);
            }
        }
        while(x > 1){
            x/=2;
            ans.push_back(x);
        }
        cout<<ans.size()<<endl;
        for(ll i = 0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}