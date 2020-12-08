#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int tc;
    ll p, q;
    cin >> tc;
    while (tc--)
    {
        cin >> p >> q;
        set<ll> s;
        ll q1 = q;
        for (int i = 2; i < ll(sqrt(q1)) + 1; i++)
        {
            while (q1 % i == 0)
            {
                s.insert(i);
                q1 /= i;
            }
        }
        if (q1 > 1LL)
            s.insert(q1);
        ll max_ = 0;
        if (p % q != 0)
            max_ = p;
        for (auto i : s)
        {
            ll g = p;
            while (g % q == 0)
            {
                g /= i;
            }
            max_ = max(max_, g);
        }
        cout << max_ << '\n';
    }

    return 0;
}