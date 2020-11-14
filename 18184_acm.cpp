#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{

    bool reverse_b = false;
    cin >> n >> k;
    if (k > (1 << n) - k)
    {
        reverse_b = true;
        k = min(k, (1 << n) - k);
    }
    vector<int> bit(n, 0);
    int m = 0;
    while ((1 << m) <= k)
    {
        m++;
    }
    m -= 1;
    int t = k, c = n - 1 - m;
    while (t > 0)
    {
        if (t >= (1 << m))
        {
            bit[c] = 1;
            t -= (1 << m);
        }
        m -= 1;
        c++;
    }

    /*
    for (auto &p : bit)
        cout << p << " ";
    */
    vector<int> ans;
    for (int index = 0; index < n; index++)
    {
        if (bit[index] && (n - 1 - index > 0))
        {
            for (int i = 0; i < (1 << (n - 1 - index)); i++)
            {
                ans.push_back(i | (1 << (n - 1 - index)));
            }
        }
        if (bit[index] && (n - 1 - index == 0))
        {
            ans.push_back(1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << "YES" << '\n';
    if (reverse_b)
    {
        bool check[1 << 14];
        memset(check, false, sizeof(check));
        for (auto &p : ans)
            check[p] = true;
        for (int i = 0; i < (1 << n); i++)
        {
            if (!check[i])
                cout << i << " ";
        }
    }
    else
    {
        for (auto &p : ans)
            cout << p << " ";
    }
    cout << '\n';

    return 0;
}