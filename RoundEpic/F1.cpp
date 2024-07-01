#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll max_operations(vector<ll>& a) {
    ll n = a.size();
    ll operations_count = 0;
    
    while (true) {
        ll i = 0;
        while (i < a.size() - 1) {
            if (a[i] == i + 1) {
                operations_count++;

                a.erase(a.begin() + i);
                a.erase(a.begin() + i); 
                break;
            }
            i++;
        }
        
        if (i == a.size() - 1) {
            break;
        }
    }
    
    return operations_count;
}

int main() {
    
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<max_operations(a)<<endl;
    }
    return 0;
}
