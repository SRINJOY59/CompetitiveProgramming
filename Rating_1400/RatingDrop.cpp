#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll fourMultiple = n/4;
        ll rem = n - fourMultiple;
        ll sum = 4*(rem/3);
        ll extra = rem%3;
        if(extra == 1){
            sum += 1;
        }
        else if(extra == 2){
            sum += 3;
        }
        ll maxTwoPower = 0;
        ll val = 1;
        while(val < n){
            val *= 2;
            maxTwoPower++;
        }
        if(val > n){
            maxTwoPower--;
        }
        ll prev = 0;
        while(maxTwoPower >= 2){
            
            ll temp = pow(2, maxTwoPower);
            
            ll available = n/temp;
            available -= prev;
            sum += available*(maxTwoPower + 1);
            
            prev += available;
            maxTwoPower--;
        }
        cout<<sum<<"\n";
    }
    return 0;
}