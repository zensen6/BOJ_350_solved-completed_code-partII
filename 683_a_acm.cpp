#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first <= b.first;
}

int main()
{

    ll t, n, w, x, c;
    cin >> t;
    while (t--)
    {
        c = 0;
        cin >> n >> w;
        bool done = false;
        vector<pair<ll, ll>> items(n, {0, 0});
        vector<ll> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            items[i] = {x, i + 1};
        }

        ll s = 0;
        for (auto &p : items)
        {
            if (p.first >= (w + 1) / 2 && p.first <= w)
            {
                done = true;
                cout << 1 << '\n';
                cout << p.second << '\n';
                break;
            }
        }
        if (!done)
        {
            for (auto &p : items)
            {
                if (p.first < (w + 1) / 2)
                {
                    s += p.first;
                    ans.push_back(p.second);
                    c++;
                }
                if (s >= (w + 1) / 2 && s <= w)
                {
                    done = true;
                    cout << c << '\n';
                    for (auto &k : ans)
                    {
                        cout << k << " ";
                    }
                    cout << '\n';
                    break;
                }
                if (s > w)
                {
                    break;
                }
            }
        }
        if (!done)
            cout << -1 << '\n';
    }
}