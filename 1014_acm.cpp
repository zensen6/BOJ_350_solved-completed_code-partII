#include <bits/stdc++.h>
#define MAX 13
using namespace std;

int d[MAX * MAX][1 << MAX], n, m;
int arr[180];

int proc(int index, int s)
{
    int &ret = d[index][s];
    if (ret != -1)
        return ret;

    ret = 0;
    if (index == n * m)
        return 0;
    int t = s >> 1;
    t |= (arr[index + 1 + m] == 1 ? (1 << m) : 0);
    if (s & 1)
        ret = max(ret, proc(index + 1, t));
    else
    {
        ret = max(ret, proc(index + 1, t));
        if ((index % m != m - 1) && (index % m != 0))
        {
            t |= 1;
            t |= (1 << m);
            t |= (1 << (m - 2));
        }
        else if (index % m == m - 1)
        {
            t |= (1 << (m - 2));
        }
        else
        {
            t |= 1;
            t |= (1 << m);
        }
        ret = max(ret, proc(index + 1, t) + 1);
    }
    return ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        memset(d, -1, sizeof(d));
        memset(arr, -1, sizeof(arr));
        char nmap[13][13];
        char map[13][13];

        scanf("%d %d", &n, &m);
        getchar();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%1c", &nmap[i][j]);
            }
            getchar();
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                map[i][j] = nmap[n - i - 1][m - j - 1];
            }
        }

        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 'x')
                    arr[c++] = 1;
                else
                    arr[c++] = 0;
            }
        }
        int s = 0;
        for (int i = 0; i <= m; i++)
        {
            if (arr[i] == 1)
                s |= (1 << i);
        }
        if (n == 1 && m == 1)
        {
            if (arr[0] == 0)
                printf("%d\n", 1);
        }
        else
            printf("%d\n", proc(0, s));
    }

    return 0;
}
