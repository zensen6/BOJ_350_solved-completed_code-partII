#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;

int m, n;
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
char arr[2001][2001];

ll pow_(ll x, ll y)
{
    if (y == 0)
        return 1LL;
    if (y == 1LL)
        return x;
    else
    {
        if (y & 1LL)
        {
            ll tmp = pow_(x, y / (2LL)) % MOD;
            return (((tmp * tmp) % MOD) * x) % MOD;
        }
        else
        {
            ll tmp = pow_(x, y / (2LL)) % MOD;
            return (tmp * tmp) % MOD;
        }
    }
}

bool inrange(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}

int main()
{

    scanf("%d %d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1c", &arr[i][j]);
        }
        getchar();
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool surrounded = true;
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (inrange(ny, nx))
                {
                    if (arr[ny][nx] != arr[i][j])
                    {
                        surrounded = false;
                    }
                }
            }
            if (surrounded)
                c++;
        }
    }
    printf("%lld\n", pow_(2LL, c) % MOD);

    return 0;
}