#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll eval(ll a, ll b, char op) {
    if (op == '+'){
        return a + b;
    } 
    else{
         return a * b;
    }
}

ll memo(string &str, ll index, ll count, vector<vector<ll>>&dp){
    ll mini = LLONG_MAX;
    if(dp[index][count] != -1){
        return dp[index][count];
    }
    //base case
    if(count == 0){
        return stoll(str.substr(index));
    }
    ll n = str.length();
    for(ll i = index;i<n - count;i++){
        ll val1 = stoll(str.substr(index, i - index + 1));

        ll val2 = memo(str, i + 1, count - 1, dp);

        mini = min(mini, eval(val1, val2, '*'));

        mini = min(mini, eval(val1, val2, '+'));
    }
    dp[index][count] = mini;
    return dp[index][count];
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<ll>> dp(n, vector<ll>(n, -1));
        ll allowed = n-2;
        cout << memo(s, 0, allowed , dp) << endl;
    }
    return 0;
}
