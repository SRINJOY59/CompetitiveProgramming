#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin>>n;
    ll max_length = -1;
    ll max_breadth = -1;
    while(n > 0){
        char ch;
        ll x, y;
        cin>>ch>>x>>y;
        if(ch == '+'){
            ll maxi = max(x, y);
            ll mini = min(x, y);
            x = maxi;
            y = mini;
            max_length = max(max_length, x);
            max_breadth = max(max_breadth, y);
        }
        else{
            ll maxi = max(x, y);
            ll mini = min(x, y);
            // cout<<maxi<<" "<<mini<<endl;
            if(max_length <= maxi && max_breadth <= mini){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        n--;
    }
    return 0;
}