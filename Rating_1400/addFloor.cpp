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
        for(ll i = 0;i<n;i++){
            cin>>arr[i];
        }
        
        if(n == 1){
            cout<<0<<endl;
            continue;
        }
        ll mini = *min_element(arr.begin(), arr.end());
        ll maxi = *max_element(arr.begin(), arr.end());
        ll steps = 0;
        vector<ll>S;
        while(mini != maxi){
            if(mini%2 == 0){
                mini = mini/2;
                maxi = (maxi)/2;
                S.push_back(0);
            }
            else{
                mini = (mini+1)/2;
                maxi = (maxi+1)/2;
                S.push_back(1);
            }
            steps++;
        }
        if(steps <= n){
            cout<<steps<<endl;
            for(ll i = 0;i<steps;i++){
                cout<<S[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<steps<<endl;
        }
    }
    return 0;
}