#include <bits/stdc++.h>
using namespace std;

int n, tc, x, y;
int d[2001][2001];
int s[2001];

void proc()
{
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++)
    {
        d[i][i] = 1;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int start = 0; start <= n - len; start++)
        {
            int end = start + len - 1;
            if (start + 1 > end - 1 && s[start] == s[end])
            {
                d[start][end] = 1;
            }
            else if (s[start] == s[end] && d[start + 1][end - 1])
            {
                d[start][end] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    proc();
    cin >> tc;
    while (tc--)
    {
        cin >> x >> y;
        if (d[x - 1][y - 1])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}