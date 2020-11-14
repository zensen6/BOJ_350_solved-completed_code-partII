#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll mod(ll x, ll y)
{
    if (x % y < 0)
        return x % y + y;
    return x % y;
}

ll fastmul(ll x, ll y)
{
    if (y == 0)
        return 1LL;
    if (y == 1)
        return mod(x, MOD);
    if (y & 1)
    {
        ll tmp = mod(fastmul(x, y - 1), MOD);
        return mod(tmp * x, MOD);
    }
    else
    {
        ll tmp = mod(fastmul(x, y / 2), MOD);
        return (tmp * tmp) % MOD;
    }
}

ll f[51];
ll bino[60][60];
ll n, m;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bino[1][0] = 1LL;
    bino[1][1] = 1LL;
    for (int i = 2; i <= 51; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
                bino[i][j] = 1LL;
            else
            {
                bino[i][j] = mod(bino[i - 1][j - 1] + bino[i - 1][j], MOD);
            }
        }
    }
    cin >> n >> m;
    f[0] = n;
    f[1] = mod((n * (n + 1)) / 2, MOD);
    for (int k = 2; k <= m; k++)
    {
        ll sum = 0;
        for (int p = 0; p <= k - 1; p++)
        {
            sum += mod(bino[k + 1][p] * f[p], MOD);
        }
        ll NK = fastmul(n + 1, k + 1);
        ll PO = fastmul(k + 1, MOD - 2);
        f[k] = mod(NK - 1 - sum, MOD);
        f[k] = mod(f[k] * PO, MOD);
    }
    cout << f[m] % MOD << '\n';
    return 0;
}