#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

char arr[501][501];
int cur[501][501];

int r1, r2, c1, c2;

bool inrange(int y, int x, int n, int m)
{

    if (y < 1 || y > n || x < 1 || x > m)
        return false;
    return true;
}
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int valid(int y, int x, int n, int m)
{

    int ans = 0;

    if ((y == r2) && (x == c2) && (cur[y][x] <= 0))
        return 1;
    cur[y][x] -= 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inrange(ny, nx, n, m))
        {

            if ((cur[ny][nx] == 1) || ((cur[ny][nx] == 0) && (ny == r2) && (nx == c2)))
            {

                ans += valid(ny, nx, n, m);
            }
        }
    }
    return ans;
}

int valid1(int y, int x, int n, int m)
{

    bool cannot = true;
    for (int i = 0; i < 4; i++)
    {

        int ny = y + dy[i];
        int nx = x + dx[i];
        if (cur[ny][nx] == 1)
            cannot = false;
    }
    return cannot;
}

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            scanf("%1c", &arr[i][j]);
            if (arr[i][j] == '.')
            {
                cur[i][j] = 1;
            }
            else
                cur[i][j] = 0;
        }
        getchar();
    }

    scanf("%d %d", &r1, &c1);
    getchar();
    scanf("%d %d", &r2, &c2);

    if ((r1 == r2) && (c1 == c2))
    {
        if (valid1(r1, c1, n, m))
        {
            printf("NO\n");
        }
        else
            printf("YES\n");
    }

    else if (valid(r1, c1, n, m))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}