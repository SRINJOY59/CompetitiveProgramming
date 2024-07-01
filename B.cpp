#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x, y, k;
        cin>>x>>y>>k;
        ll rem = x%y;
        ll div = x/y;
        ll extra = (div+1)*y - x;
        while(x > 1){
            if(k >= extra){
                k -= extra;
                x += extra;
                while(x%y == 0){
                    x/=y;
                }
                div = x/y;
                extra = (div + 1)*y - x;
            }
            else{
                x += k;
                break;
            }
        }
        if(x == 1){
            ll val = k/(y - 1);
            ll rem = k%(y-1);
            x += rem;
        }
        cout<<x<<endl;
    }
    return 0;
}