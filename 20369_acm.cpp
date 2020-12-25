#include <bits/stdc++.h>
using namespace std;

int n, maxl = 200001, maxr = -1, lo, lz, ro, rz, lim[2][2];
char arr[2][200001];
int l[2][200001], r[2][200001], lk[2][200001], rk[2][200001], A[2][200001], checkl[200001], checkr[200001];

int main()
{

    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(lk, 0, sizeof(lk));
    memset(rk, 0, sizeof(rk));
    memset(A, 0, sizeof(A));
    memset(checkl, 0, sizeof(checkl));
    memset(checkr, 0, sizeof(checkr));
    lim[0][0] = 200001, lim[1][0] = 200001, lim[0][1] = -1, lim[1][1] = -1;

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%1c", &arr[0][i]);
    }
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%1c", &arr[1][i]);
    }

    if (arr[0][n - 1] == '#')
    {
        l[1][n - 1] = 1;
    }
    if (arr[1][n - 1] == '#')
    {
        l[0][n - 1] = 1;
    }
    if (arr[0][0] == '#')
    {
        r[1][0] = 1;
    }
    if (arr[1][0] == '#')
    {
        r[0][0] = 1;
    }
    if (n >= 3)
    {
        bool cl = false, cr = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (cl)
                checkl[i] = 1;
            if (arr[0][i] == '#' || arr[1][i] == '#')
            {
                maxr = max(maxr, i);
                cl = true;
                if (arr[0][i] == '#')
                    lim[0][1] = max(lim[0][1], i);
                if (arr[1][i] == '#')
                    lim[1][1] = max(lim[1][1], i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (cr)
                checkr[i] = 1;
            if (arr[0][i] == '#' || arr[1][i] == '#')
            {
                maxl = min(maxl, i);
                cr = true;
                if (arr[0][i] == '#')
                    lim[0][0] = min(lim[0][0], i);
                if (arr[1][i] == '#')
                    lim[1][0] = min(lim[1][0], i);
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (checkl[i])
            {
                if (arr[1][i] == '#' && arr[0][i] == '.')
                {
                    l[0][i] = min(3 + l[0][i + 1], 2 + l[1][i + 1]);
                    l[1][i] = min(2 + l[0][i + 1], 1 + l[1][i + 1]);
                }
                else if (arr[0][i] == '#' && arr[1][i] == '.')
                {
                    l[0][i] = min(1 + l[0][i + 1], 2 + l[1][i + 1]);
                    l[1][i] = min(2 + l[0][i + 1], 3 + l[1][i + 1]);
                }
                else if (arr[0][i] == '#' && arr[1][i] == '#')
                {
                    l[0][i] = min(3 + l[0][i + 1], 2 + l[1][i + 1]);
                    l[1][i] = min(2 + l[0][i + 1], 3 + l[1][i + 1]);
                }
                else
                {
                    l[0][i] = min(1 + l[0][i + 1], 2 + l[1][i + 1]);
                    l[1][i] = min(2 + l[0][i + 1], 1 + l[1][i + 1]);
                }
            }
            else if (i == maxr)
            {
                if (arr[1][i] == '#')
                    l[0][i] = 1;
                if (arr[0][i] == '#')
                    l[1][i] = 1;
            }
            if (i > maxl && i < maxr)
            {
                lk[0][i] = i - maxl + (lo == 1 ? 1 : 0);
                lk[1][i] = i - maxl + (lz == 1 ? 1 : 0);
                rk[0][i] = maxr - i + (ro == 1 ? 1 : 0);
                rk[1][i] = maxr - i + (rz == 1 ? 1 : 0);
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (checkr[i])
            {
                if (arr[0][i] == '.')
                    r[1][i] = min(2 + r[0][i - 1], 1 + r[1][i - 1]);
                else
                    r[1][i] = min(2 + r[0][i - 1], 3 + r[1][i - 1]);
                if (arr[1][i] == '.')
                    r[0][i] = min(1 + r[0][i - 1], 2 + r[1][i - 1]);
                else
                    r[0][i] = min(3 + r[0][i - 1], 2 + r[1][i - 1]);
            }
            else if (i == maxl)
            {
                if (arr[1][i] == '#')
                    r[0][i] = 1;
                if (arr[0][i] == '#')
                    r[1][i] = 1;
            }
        }

        for (int j = 0; j <= 1; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i > maxl && i < maxr)
                {
                    int a = lk[j][i] + lk[1 - j][i] + 1 + l[1 - j][i + 1] - (arr[0][maxl] == arr[1][maxl] ? 1 : 0);
                    int b = rk[j][i] + rk[1 - j][i] + 1 + r[1 - j][i - 1] - (arr[0][maxr] == arr[1][maxr] ? 1 : 0);
                    int c = rk[j][i] + rk[j][i] + 1 + r[j][i - 1];
                    int d = lk[j][i] + lk[j][i] + 1 + l[j][i + 1];
                    if (maxl == lim[j][0] && maxr == lim[j][1] && lim[1 - j][0] <= i && lim[1 - j][1] >= i)
                    {
                        A[j][i] = min(a, b);
                    }
                    else if (maxl == lim[j][0] && lim[1 - j][0] <= i)
                    {
                        A[j][i] = min(min(a, b), c);
                    }
                    else if (maxr == lim[j][1] && lim[1 - j][1] >= i)
                    {
                        A[j][i] = min(min(a, b), d);
                    }
                    else
                    {
                        A[j][i] = min(min(a, b), min(c, d));
                    }
                }
                else
                {
                    A[j][i] = max(l[j][i], r[j][i]);
                }
            }
        }

        for (int j = 0; j <= 1; j++)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d ", A[j][i]);
            }
            printf("\n");
        }
    }
    else if (n == 2)
    {
        for (int i = 0; i <= 1; i++)
        {
            if (arr[0][i] == '#' && arr[1][1 - i] == '#')
            {
                A[1][i] = 3;
            }
            else if (arr[0][1 - i] == '#')
            {
                A[1][i] = 2;
            }
            else if (arr[0][i] == '#' || arr[1][1 - i] == '#')
            {
                A[1][i] = 1;
            }

            if (arr[1][i] == '#' && arr[0][1 - i] == '#')
            {
                A[0][i] = 3;
            }
            else if (arr[1][1 - i] == '#')
            {
                A[0][i] = 2;
            }
            else if (arr[1][i] == '#' || arr[0][1 - i] == '#')
            {
                A[0][i] = 1;
            }
        }

        for (int i = 0; i <= 1; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        if (arr[0][0] == '#' && arr[1][0] == '#')
        {
            printf("%d\n%d\n", 1, 1);
        }
        else if (arr[0][0] == '#')
        {
            printf("%d\n%d\n", 0, 1);
        }
        else if (arr[1][0] == '#')
        {
            printf("%d\n%d\n", 1, 0);
        }
        else
        {
            printf("%d\n%d\n", 0, 0);
        }
    }

    return 0;
}
