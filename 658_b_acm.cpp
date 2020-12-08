#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = 0;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        reverse(v.begin(), v.end());
        ans += 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i - 1] == 1 && v[i] > 1)
            {
                if (ans & 1)
                {
                    ans += 2;
                }
                else
                    ans += 1;
            }
            else if (v[i - 1] == 1 && v[i] == 1)
            {
                ans += 1;
            }
            else if (v[i - 1] > 1 && v[i] > 1)
            {
                ans += 2;
            }
            else
            {
                ans += 1;
            }
        }
        if (ans & 1)
            cout << "First" << '\n';
        else
            cout << "Second" << '\n';
    }

    return 0;
}
