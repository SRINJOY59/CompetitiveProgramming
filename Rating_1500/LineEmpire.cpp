#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, a, b;
        cin>>n>>a>>b;
        ll center = 0;
        vector<ll>kingdoms(n);
        for(ll i = 0;i<n;i++){
            cin>>kingdoms[i];
        }
        vector<ll>dp(n+1, 0);
        ll ans = b*kingdoms[0];
        for(ll i = 1;i<n;i++){
            if(a*abs(kingdoms[i-1] - center) + b*(kingdoms[i] - kingdoms[i-1]) <= b*abs(kingdoms[i] - center)){
                ans += a*abs(kingdoms[i-1] - center) + b*(kingdoms[i] - kingdoms[i-1]);
                center = kingdoms[i-1];
                cout<<center<<endl;
            }
            else{
                ans += b*abs(kingdoms[i] - center);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}