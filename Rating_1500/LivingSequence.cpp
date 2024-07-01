#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>digits;
        while(n > 0){
            digits.push_back(n%9);
            n/=9;
        }
        reverse(digits.begin(), digits.end());
        for(ll i = 0;i<digits.size();i++){
            if(digits[i] >= 4){
                digits[i] += 1;
            }
            cout<<digits[i];
        }
        cout<<endl;
    }
    return 0;
}