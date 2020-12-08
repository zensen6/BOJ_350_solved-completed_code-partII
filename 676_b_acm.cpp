#include <bits/stdc++.h>
using namespace std;
int tc, n, x;
char arr[201][201];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
bool check[201][201];

bool inrange(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < n;
}

bool dfs(int y, int x) // here(y,x);
{

    check[y][x] = true;
    if ((y == n - 2 && x == n - 1) || (y == n - 1 && x == n - 2))
        return true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (y == 0 && x == 0)
        {
            if (!check[ny][nx] && inrange(ny, nx))
            {
                if (dfs(ny, nx))
                    return true;
            }
        }
        else if (!check[ny][nx] && inrange(ny, nx) && (arr[y][x] == arr[ny][nx]))
        {
            if (dfs(ny, nx))
                return true;
        }
    }
    return false;
}

void proc()
{
    if (!dfs(0, 0))
    {
        printf("0\n");
        return;
    }
    else
    {
        memset(check, false, sizeof(check));
        arr[n - 2][n - 1] = ((arr[n - 2][n - 1] == '0') ? '1' : '0');

        if (!dfs(0, 0))
        {
            printf("1\n");
            printf("%d %d\n", n - 1, n);
            return;
        }


        memset(check, false, sizeof(check));
        arr[n - 2][n - 1] = ((arr[n - 2][n - 1] == '0') ? '1' : '0');
        arr[n - 1][n - 2] = ((arr[n - 1][n - 2] == '0') ? '1' : '0');
        if (!dfs(0, 0))
        {
            printf("1\n");
            printf("%d %d\n", n, n - 1);
            return;
        }
        printf("2\n");
        printf("%d %d\n", n, n - 1);
        printf("%d %d\n", n - 1, n);
        return;
    }
}

int main()
{

    scanf("%d", &tc);
    getchar();
    while (tc--)
    {

        memset(check, false, sizeof(check));
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%1c", &arr[i][j]);
            }
            getchar();
        }
        proc();
    }

    return 0;
}
