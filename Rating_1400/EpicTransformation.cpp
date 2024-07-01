#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        map<ll, ll> mp;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(&cmp)> pq(cmp);

        for (auto i : mp)
        {
            pq.push({i.first, i.second});
        }

        while (pq.size() > 1)
        {
            pair<ll, ll> p1 = pq.top();
            pq.pop();
            pair<ll, ll> p2 = pq.top();
            pq.pop();
            // cout<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<endl;
            p1.second -= 1;
            p2.second -= 1;
            if (p1.second > 0)
            {
                pq.push(p1);
            }
            if (p2.second > 0)
            {
                pq.push(p2);
            }
        }

        ll ans = 0;
        if (!pq.empty())
        {
            ans = pq.top().second;
        }

        cout << ans << "\n";
    }
    return 0;
}
