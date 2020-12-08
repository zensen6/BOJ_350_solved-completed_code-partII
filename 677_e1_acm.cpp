#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
    int n;
    cin >> n;
    ull f[21], d[21][21];
    f[1] = 1ULL;
    for (int i = 1; i <= 20; i++)
    {
        d[i][0] = 1ULL;
        d[i][i] = 1ULL;
        if (i >= 2)
            f[i] = i * f[i - 1];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }
    cout << (d[n][n / 2] / 2ULL) * (2ULL * f[n / 2] / n) * (2ULL * f[n / 2] / n) << '\n';
    return 0;
}