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
        vector<int> brr(n, 0);
        int index = 0;
        int max_ = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            brr[i] = arr[i];
        }
        sort(brr.begin(), brr.end());
        if (brr[0] == brr[n - 1])
        {
            cout << -1 << '\n';
        }
        else
        {

            for (int i = 0; i < n; i++)
            {
                if (arr[i] == brr[n - 1])
                {
                    if (i > 0 && arr[i - 1] < arr[i])
                    {
                        cout << i + 1 << '\n';
                        break;
                    }
                    if (i < n - 1 && arr[i + 1] < arr[i])
                    {
                        cout << i + 1 << '\n';
                        break;
                    }
                }
            }
        }
    }

    return 0;
}