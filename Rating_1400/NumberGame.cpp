#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<long long, ll> primeFactorization(long long n) {
    map<long long, ll> factors;

    for (long long i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }

    if (n > 1) {
        factors[n]++;
    }

    return factors;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n == 1){
            cout<<"FastestFinger"<<endl;
        }
        else if(n == 2 || n&1){
            cout<<"Ashishgup"<<endl;
        }
        else{
            ll count = 0;
            while(n%2 == 0){
                n/=2;
                count++;
            }
            if(n == 1){
                
                cout<<"FastestFinger"<<endl;
            }
            else if(count == 1){
                map<ll, ll>primeFactors = primeFactorization(n);
                ll sum = 0;
                bool flag = false;
                for(auto it:primeFactors){
                    sum += it.second;
                    if(sum >= 2){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    cout<<"Ashishgup"<<endl;
                }
                else{
                    cout<<"FastestFinger"<<endl;
                }
            }
            else{
                cout<<"Ashishgup"<<endl;
            }
        }
    }
    return 0;
}