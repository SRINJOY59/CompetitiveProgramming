#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x1, x2, x3;
        cin>>x1>>x2>>x3;
        ll ans = LLONG_MAX;
        for(int a = 0;a<=1000;a++){
            ll dist = abs(a - x1) + abs(a - x2) + abs(a - x3);
            ans = min(ans, dist);
        }
        cout<<ans<<endl;
    }
    return 0;
}