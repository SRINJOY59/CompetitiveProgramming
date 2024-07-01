#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    ll diff = 0;
    ll count = 1;
    for(ll i = n/2; i < n-1;i++){
        ll val = arr[i+1] - arr[i];
        if(k >= val){
            arr[n/2] += (val/count);
            k -= val;
        }
        else if(k < val && k > 0){
            arr[n/2] += (k/count);
            k = 0;
        }
        if(k == 0){
            break;
        }
        count++;
    }
    count = 0;
    if(k > 0){
        for(ll i = n/2; i < n;i++){
            ll diff = arr[i+1] - arr[i];
            count++;
            if(diff > 0){
                ll val = count*diff;
                if(k >= val){
                    arr[n/2] += val;
                    k -= val;
                }
                if(k == 0){
                    break;
                }
            }
        }
        if(k > 0 && arr[n/2] == arr[n-1]){
            ll sz = n - (n/2);
            ll ans = (k/sz);
            arr[n/2] += ans;
        }
    }
    cout<<arr[n/2]<<endl;
    return 0;
}