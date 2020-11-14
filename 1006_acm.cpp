#include <bits/stdc++.h>
using namespace std;

int tc, n, w, d[10002], d_[10002][2], arr[10002][2], l[10002], l_[10002][2], r[10002], r_[10002][2], k[10002], k_[10002][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--)
    {
        bool l_done = false;
        bool r_done = false;
        memset(d, 0, sizeof(d));
        memset(d_, 0, sizeof(d_));
        memset(k, 0, sizeof(k));
        memset(k_, 0, sizeof(k_));
        memset(l, 0, sizeof(l));
        memset(l_, 0, sizeof(l_));
        memset(arr, 0, sizeof(arr));
        cin >> n >> w;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i][0];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i][1];
        }
        d_[1][0] = 1;
        d_[1][1] = 1;
        if (arr[1][0] + arr[1][1] <= w)
        {
            d[1] = 1;
        }
        else
        {
            d[1] = 2;
        }

        for (int i = 2; i <= n; i++)
        {
            int t = (arr[i][0] + arr[i][1] <= w) ? 0 : 1;
            if (arr[i - 1][0] + arr[i][0] <= w && arr[i - 1][1] + arr[i][1] <= w)
            {
                d[i] = min(min(d[i - 1] + 1 + t, d[i - 2] + 2), min(d_[i - 1][0] + 2, d_[i - 1][1] + 2));
            }
            else if (arr[i - 1][0] + arr[i][0] <= w)
            {
                d[i] = min(d[i - 1] + 1 + t, d_[i - 1][0] + 2);
            }
            else if (arr[i - 1][1] + arr[i][1] <= w)
            {
                d[i] = min(d[i - 1] + 1 + t, d_[i - 1][1] + 2);
            }
            else
            {
                d[i] = d[i - 1] + 1 + t;
            }

            d_[i][0] = (arr[i - 1][1] + arr[i][1] <= w) ? min(d[i - 1] + 1, d_[i - 1][1] + 1) : d[i - 1] + 1;
            d_[i][1] = (arr[i - 1][0] + arr[i][0] <= w) ? min(d[i - 1] + 1, d_[i - 1][0] + 1) : d[i - 1] + 1;
        }

        if (n >= 2)
        {
            if (arr[1][0] + arr[n][0] <= w)
            {
                l_done = true;
                l[1] = 2;
                l_[2][1] = 3;
                l_[2][0] = (arr[1][1] + arr[2][1] <= w) ? 2 : 3;
                l[2] = (arr[2][0] + arr[2][1] <= w) ? 3 : (arr[1][1] + arr[2][1] <= w) ? 3 : 4;
                for (int i = 3; i <= n - 1; i++)
                {
                    int t = (arr[i][0] + arr[i][1] <= w) ? 0 : 1;
                    if (arr[i - 1][0] + arr[i][0] <= w && arr[i - 1][1] + arr[i][1] <= w)
                    {
                        l[i] = min(min(l[i - 1] + 1 + t, l[i - 2] + 2), min(l_[i - 1][0] + 2, l_[i - 1][1] + 2));
                    }
                    else if (arr[i - 1][0] + arr[i][0] <= w)
                    {
                        l[i] = min(l[i - 1] + 1 + t, l_[i - 1][0] + 2);
                    }
                    else if (arr[i - 1][1] + arr[i][1] <= w)
                    {
                        l[i] = min(l[i - 1] + 1 + t, l_[i - 1][1] + 2);
                    }
                    else
                    {
                        l[i] = l[i - 1] + 1 + t;
                    }

                    l_[i][0] = (arr[i - 1][1] + arr[i][1] <= w) ? min(l[i - 1] + 1, l_[i - 1][1] + 1) : l[i - 1] + 1;
                    l_[i][1] = (arr[i - 1][0] + arr[i][0] <= w) ? min(l[i - 1] + 1, l_[i - 1][0] + 1) : l[i - 1] + 1;
                }
                if (n >= 3)
                    l_[n][0] = (arr[n - 1][1] + arr[n][1] <= w) ? min(l[n - 1] + 1, l_[n - 1][1] + 1) : l[n - 1] + 1;
            }
            if (arr[1][1] + arr[n][1] <= w)
            {
                r_done = true;
                r[1] = 2;
                r_[2][0] = 3;
                r_[2][1] = (arr[1][0] + arr[2][0] <= w) ? 2 : 3;
                r[2] = (arr[2][0] + arr[2][1] <= w) ? 3 : (arr[1][0] + arr[2][0] <= w) ? 3 : 4;
                for (int i = 3; i <= n - 1; i++)
                {
                    int t = (arr[i][0] + arr[i][1] <= w) ? 0 : 1;
                    if (arr[i - 1][0] + arr[i][0] <= w && arr[i - 1][1] + arr[i][1] <= w)
                    {
                        r[i] = min(min(r[i - 1] + 1 + t, r[i - 2] + 2), min(r_[i - 1][0] + 2, r_[i - 1][1] + 2));
                    }
                    else if (arr[i - 1][0] + arr[i][0] <= w)
                    {
                        r[i] = min(r[i - 1] + 1 + t, r_[i - 1][0] + 2);
                    }
                    else if (arr[i - 1][1] + arr[i][1] <= w)
                    {
                        r[i] = min(r[i - 1] + 1 + t, r_[i - 1][1] + 2);
                    }
                    else
                    {
                        r[i] = r[i - 1] + 1 + t;
                    }

                    r_[i][0] = (arr[i - 1][1] + arr[i][1] <= w) ? min(r[i - 1] + 1, r_[i - 1][1] + 1) : r[i - 1] + 1;
                    r_[i][1] = (arr[i - 1][0] + arr[i][0] <= w) ? min(r[i - 1] + 1, r_[i - 1][0] + 1) : r[i - 1] + 1;
                }
                if (n >= 3)
                    r_[n][1] = (arr[n - 1][0] + arr[n][0] <= w) ? min(r[n - 1] + 1, r_[n - 1][0] + 1) : r[n - 1] + 1;
            }
            if (arr[1][0] + arr[n][0] <= w && arr[1][1] + arr[n][1] <= w)
            {
                k[1] = 2;
                k_[2][0] = 3;
                k_[2][1] = 3;
                if (arr[2][0] + arr[2][1] <= w)
                {
                    k[2] = 3;
                }
                else
                {
                    k[2] = 4;
                }

                for (int i = 3; i <= n - 1; i++)
                {
                    int t = (arr[i][0] + arr[i][1] <= w) ? 0 : 1;
                    if (arr[i - 1][0] + arr[i][0] <= w && arr[i - 1][1] + arr[i][1] <= w)
                    {
                        k[i] = min(min(k[i - 1] + 1 + t, k[i - 2] + 2), min(k_[i - 1][0] + 2, k_[i - 1][1] + 2));
                    }
                    else if (arr[i - 1][0] + arr[i][0] <= w)
                    {
                        k[i] = min(k[i - 1] + 1 + t, k_[i - 1][0] + 2);
                    }
                    else if (arr[i - 1][1] + arr[i][1] <= w)
                    {
                        k[i] = min(k[i - 1] + 1 + t, k_[i - 1][1] + 2);
                    }
                    else
                    {
                        k[i] = k[i - 1] + 1 + t;
                    }

                    k_[i][0] = (arr[i - 1][1] + arr[i][1] <= w) ? min(k[i - 1] + 1, k_[i - 1][1] + 1) : k[i - 1] + 1;
                    k_[i][1] = (arr[i - 1][0] + arr[i][0] <= w) ? min(k[i - 1] + 1, k_[i - 1][0] + 1) : k[i - 1] + 1;
                }
            }
            if (l_done && r_done)
            {
                //cout << "aaaa" << '\n';
                //cout << d[n] << " " << l_[n][0] << " " << r_[n][1] << " " << k[n - 1] << '\n';
                cout << min(min(d[n], l_[n][0]), min(r_[n][1], k[n - 1])) << '\n';
            }
            else if (l_done)
            {
                cout << min(d[n], l_[n][0]) << '\n';
            }
            else if (r_done)
            {
                cout << min(d[n], r_[n][1]) << '\n';
            }
            else
            {
                cout << d[n] << '\n';
            }
        }
        else
        {
            cout << d[1] << '\n';
        }
    }

    return 0;
}