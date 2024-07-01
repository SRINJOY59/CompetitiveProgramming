#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll powerer5 = 0;
        ll powerer2 = 0;
        
      
        while (n % 5 == 0) {
            n /= 5;
            powerer5++;
        }
        
      
        while (n % 2 == 0) {
            n /= 2;
            powerer2++;
        }
        
        ll diff, val, count, check, powerer10;
        if (powerer5 >= powerer2) {
            diff = powerer5 - powerer2;
            val = power(10, powerer2);
            n *= val;
        
            count = 0;
            ll temp = m;
            
           
            while (m >= 2) {
                m /= 2;
                count++;
            }
            
            m = temp;
            check = min(count, diff);
            // cout<<check<<endl;
            ll val = power(10, check);
            // cout<<val<<endl;
            n *= val; 
            if(diff > count){
                ll num = diff - count;
                ll nVAL = power(5, num);
                n = n*nVAL;
            }
            
            // cout << n << endl;
            while (check > 0) {
                m /= 2;
                check--;
            }
            
            powerer10 = 0;
            while (m >= 10) {
                m /= 10;
                powerer10++;
            }
            ll val2 = power(10, powerer10);
            n *= val2; 
            n = n*m;
        } else {
            diff = powerer2 - powerer5;
            n *= power(10, powerer5); 
            count = 0;
            ll temp = m;
            
            while (m >= 5) {
                m /= 5;
                count++;
            }
            
            m = temp;
            check = min(count, diff);
            ll val1 = power(10, check);
            n *= val1; 
            if(diff > count){
                ll num = diff - count;
                ll nVAL = power(2, num);
                n = n*nVAL;
            }
            
            while (check > 0) {
                m /= 5;
                check--;
            }
            
            powerer10 = 0;
            while (m >= 10) {
                m /= 10;
                powerer10++;
            }
            ll val2 = power(10, powerer10); 
            n *= val2; 
            n = n*m;
        }
        cout << n << endl;
    }
    return 0;
}
