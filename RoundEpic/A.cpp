#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll time_taken = 0;
        n = n - 1;
        while(n > 0){
            time_taken += k;
            n--;
        }
        ll ans = time_taken + 1;
        cout<<ans<<"\n";
    }
    return 0;
}