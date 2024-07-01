#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin>>n;
    cout<<2*n<<endl;
    if(n <= 4){
        cout<<n<<endl;
    }
    else{
        string ans = "";
        while(n >= 4){
            ans += "4";
            n -= 4;
        }
        if(n > 0){
            ans += to_string(n);
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
    return 0;
}