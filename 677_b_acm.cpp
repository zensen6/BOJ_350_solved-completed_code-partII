#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n, 0);
        int l = n - 1, r = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                l = min(l, i);
                r = max(r, i);
            }
        }
        int c = 0;
        for (int i = l; i <= r; i++)
        {
            if (arr[i] == 0)
                c++;
        }
        if (l == n - 1 && r == 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << c << '\n';
        }
    }

    return 0;
}