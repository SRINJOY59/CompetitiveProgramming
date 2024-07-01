#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
    }
    if(n == 1 || n == 2){
        cout<<0<<endl;
        for(ll i = 0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
 
    sort(arr.begin(),arr.end());
    vector<ll>final(n, 0);
    ll cnt = 0;
    for(ll i = 1;i<n;i+=2){
        final[i] = arr[cnt];
        cnt++;
    }
    ll temp = n;
    
    for(ll i = 1;i<n-1;i+=2){
        
        ll upper = upper_bound(arr.begin() + cnt, arr.end(), final[i]) - arr.begin();
        if(upper < n && final[i-1] <= final[i]){
            final[i-1] = arr[upper];
            cnt = upper+1;
        }
 
        ll upper2 = upper_bound(arr.begin() + cnt, arr.end(), final[i]) - arr.begin();
        if(upper2 < n && final[i+1] <= final[i]){
            final[i+1] = arr[upper2];
 
            cnt = upper2+1;
        }
    }
    for(ll i = 0;i<temp;i++){
        if(final[i] == 0){
            final[i] = arr[cnt];
            if(cnt == n){
                final[i] = arr[2];
            }
        }
    }
    ll ans = 0;
    for(ll i = 1;i<n-1;i+=2){
        if(final[i-1] > final[i] && final[i] < final[i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    for(ll i = 0;i<temp;i++){
        cout<<final[i]<<" ";
    }
    cout<<endl;
    return 0;
}
