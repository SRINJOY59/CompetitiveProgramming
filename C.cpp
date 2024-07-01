#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, l, r;
        cin>>n>>l>>r;
        vector<ll>arr(n);
        for(ll i = 0;i<n;i++){
            cin>>arr[i];
        }
        // sort(arr.begin(), arr.end());
        ll start = 0;
        ll end = n-1;
        ll ans = 0;
        ll sum = 0;
        for(ll i = 0;i<n;i++){
            sum += arr[i];
            while(sum > r){
                sum -= arr[start];
                start++;
            }
            if(sum >= l && sum <= r){
                ans++;
                sum = 0;
                start = i+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}