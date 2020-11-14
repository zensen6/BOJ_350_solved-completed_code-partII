#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tc, n;

int main()
{
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        ll k = n;
        vector<pair<int, int>> ans;
        while (k > 0)
        {
            int c = 0;
            while (k % 3 == 0)
            {
                k /= 3;
                c++;
            }

            ll tmp = 0LL;
            while ((1LL << tmp) <= k)
                tmp++;
            tmp--;
            while ((k - (1LL << tmp)) % 3LL != 0)
                tmp--;
            k -= (1LL << tmp);
            if (ans.size() > 0)
            {
                int p = ans[ans.size() - 1].second;
                ans.push_back({tmp, p + c});
            }
            else
                ans.push_back({tmp, c});
        }
        cout << ans.size() << '\n';
        for (auto &p : ans)
        {
            cout << p.first << " " << p.second << '\n';
        }
    }

    return 0;
}