#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t, n, x;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        map<ll, int> m;
        for (auto &p : v)
        {
            m[p]++;
        }
        bool yes = false;
        map<ll, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++)
        {
            if (it->second > 1)
            {
                yes = true;
                cout << "YES" << '\n';
                break;
            }
        }

        if (!yes)
            cout << "NO" << '\n';
    }

    return 0;
}