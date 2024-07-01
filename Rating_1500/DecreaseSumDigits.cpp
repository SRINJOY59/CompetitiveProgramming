#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    ll temp_t = t;
    ll count = 0;
    while (t--)
    {
        string n;
        ll s;
        cin >> n >> s;
        
        string t = "";
        ll sum = 0;
        ll s_dig = 0;
        for(ll i = 0;i<n.length();i++){
            s_dig += n[i] - '0';
        }
        if(s_dig <= s){
            cout<<0<<endl;
            continue;
        }
        for (ll i = 0; i < n.length(); i++)
        {
            sum += n[i] - '0';
            if (sum >= s)
            {
                if (i > 0)
                {
                    ll x = t.length();
                    bool flag = false;
                    for(ll j = x-1;j>=0;j--){
                        if(t[j] != '9'){
                            t[j] += 1;
                            flag = true;
                            break;
                        }
                        else{
                            for(ll k = j;k>=0;k--){
                                if(t[k] != '9'){
                                     t[k] += 1;
                                     flag = true;
                                     break;
                                }
                                else{
                                    t[k] = '0';
                                }
                            }
                            break;
                        }
                    }
                    if(!flag){
                        t = "";
                        t += '1';
                        for (ll j = 0; j < n.length(); j++)
                        {
                            t += '0';
                        }
                        break;
                    }
                    for (ll j = i; j < n.length(); j++)
                    {
                        t += '0';
                    }
                    break;
                }
                else
                {
                    t +='1';
                    for (ll j = 0; j < n.length(); j++)
                    {
                        t += '0';
                    }
                    break;
                }
            }
            else
            {
                t += n[i];
            }
        }
        // cout<<t<<endl;
        ll num1 = stoll(t);
        ll num2 = stoll(n);
        ll ans = num1 - num2;
        cout<<ans<<endl;
    }
    return 0;
}