#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>arr(n);
        for(ll i =0;i<n;i++){
            cin>>arr[i];
        }
        ll ans = -1;
        for(ll i = 0;i<n;i++){
            if(ans < arr[i] + i){
                ans = arr[i] + i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}