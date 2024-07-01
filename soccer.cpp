#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x1, y1;
        cin>>x1>>y1;
        ll x2, y2;
        cin>>x2>>y2;
        ll diff1 = x1 - y1;
        ll diff2 = x2 - y2;
        if(diff1 > 0 && diff2 < 0 || diff1 < 0 && diff2 > 0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}