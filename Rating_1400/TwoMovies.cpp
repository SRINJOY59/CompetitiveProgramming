#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    ll temp_t = t;
    ll count = 0;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        vector<ll>b(n);
        for(ll i = 0;i<n;i++){
            cin>>a[i];
        }
        for(ll i = 0;i<n;i++){
            cin>>b[i];
        }
        
        ll asum = 0;
        ll bsum = 0;
        vector<ll>same;
        for(ll i = 0;i<n;i++){
            if(a[i] != b[i]){
                if(a[i] > b[i]){
                    asum += a[i];
                }
                else{
                    bsum += b[i];
                }
            }
            else{
                same.push_back(i);
            }
        }
        ll minus = 0;
        ll plus = 0;
        for(ll i = 0;i<same.size();i++){
            if(a[same[i]] == -1){
                minus++;
            }
            
            else if(a[same[i]] == 1){
                plus++;
            }
        }
        for(ll i = 0;i<minus;i++){
            if(asum > bsum){
                asum--;
            }
            else{
                bsum--;
            }
        }
        for(ll i = 0;i<plus;i++){
            if(asum > bsum){
                bsum++;
            }
            else{
                asum++;
            }
        }
        ll tot_a = 0;
        ll tot_b = 0;
        for(ll i  =0;i<n;i++){
            tot_a += a[i];
            tot_b += b[i];
        }

        ll ans = min(asum, bsum);
        if(ans < 0){
            if(tot_a >= 0 || tot_b >= 0){
                ans = 0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}