#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, x;
    int arr[1002];
    cin >> t;
    while (t--)
    {
        bool done = false;
        int ans = 0;
        cin >> n >> m;

        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (arr[x] == 0)
                arr[x] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            if (arr[x] == 1)
                arr[x] = 2;
        }
        for (int i = 1; i <= 1000; i++)
        {
            if (arr[i] == 2)
            {
                cout << "YES" << '\n';
                done = true;
                cout << 1 << " " << i << '\n';
                break;
            }
        }
        if (!done)
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}