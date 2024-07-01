#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll q;
        cin >> q;
        vector<bool> A(26, false);
        vector<ll> countA(26, 0);
        vector<bool> B(26, false);
        vector<ll> countB(26, 0);
        A[0] = true;
        B[0] = true;
        while (q--)
        {
            ll d, k;
            string s;
            cin >> d >> k >> s;

            if (d == 1)
            {
                for (char c : s)
                {
                    ll val = c - 'a';
                    A[val] = true;
                    countA[val] += k;
                }
            }
            else
            {
                for (char c : s)
                {
                    ll val = c - 'a';
                    B[val] = true;
                    countB[val] += k;
                }
            }

            bool flag = false;
            bool flag1 = false;
            if (d == 1)
            {
                for (ll i = 0; i < 25; i++)
                {
                    if (A[i])
                    {
                        for (ll j = i + 1; j < 26; j++)
                        {
                            if (B[j])
                            {
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (flag)
                        break;
                }
                if (!flag)
                {
                    for (ll i = 0; i < 26; i++)
                    {
                        if (A[i] == true)
                        {
                            for (ll j = 0; j < 26; j++)
                            {
                                if(B[j]){
                                    if(j < i){
                                        flag1 = true;
                                        break;
                                    }
                                }
                            }
                            if(flag1){
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                for (ll i = 0; i < 26; i++)
                {
                    if (B[i])
                    {
                        for (ll j = 0; j < i; j++)
                        {
                            if (A[j])
                            {
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (flag)
                        break;
                }
                // cout<<flag<<endl;
                if (!flag)
                {
                    for (ll i = 0; i < 26; i++)
                    {
                        if (A[i] == true)
                        {
                            for (ll j = 0; j < 26; j++)
                            {
                                if(B[j]){
                                    if(j < i){
                                        flag1 = true;
                                        break;
                                    }
                                }
                            }
                            if(flag1){
                                break;
                            }
                        }
                    }
                }

            }

            if (flag)
            {
                cout << "YES" << endl;
            }
            else if(flag1){
                cout<<"NO"<<endl;
            }
            else
            {
                bool check = false;
                for (ll i = 0; i < 26; i++)
                {

                    if (countB[i] > countA[i])
                    {
                        check = true;
                        break;
                    }
                }
                if (check)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}
