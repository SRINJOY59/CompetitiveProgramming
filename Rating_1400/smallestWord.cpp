#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string str;
    cin >> str;
    vector<bool> v(str.length(), 0);
    ll n = str.length();
    // ll acount = 0;
    for (ll i = 1; i < n; i++)
    {
        if (str[i] == 'a')
        { 
                v[i - 1]=v[i-1]^1;
                v[i] = true;
            
        }
    }
    
    for (ll i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}