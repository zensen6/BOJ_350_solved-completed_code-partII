#include <bits/stdc++.h>
#define INF 1000001
using namespace std;

int n, m, t, d;
char arr[26][26];
int dist[26][26];
int mountain[26][26];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
bool check[26][26];
int k[26][26];

bool inrange(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}

int cal(int y, int x, int ny, int nx)
{
    if (abs(mountain[y][x] - mountain[ny][nx]) > t)
        return -1;
    else if (mountain[y][x] >= mountain[ny][nx])
        return 1;
    return pow(abs(mountain[y][x] - mountain[ny][nx]), 2);
}

void proc(int sy, int sx)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    memset(check, false, sizeof(check));
    pq.push({0, {sy, sx}});
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = INF;
        }
    }

    dist[sy][sx] = 0;

    while (!pq.empty())
    {
        auto t = pq.top();
        auto loc = t.second;
        int y = loc.first;
        int x = loc.second;
        auto cost = -t.first;
        pq.pop();
        if (check[y][x])
            continue;
        check[y][x] = true;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inrange(ny, nx))
            {
                if (!check[ny][nx] && (cal(y, x, ny, nx) != -1) && (cal(y, x, ny, nx) + cost < dist[ny][nx]))
                {
                    dist[ny][nx] = cal(y, x, ny, nx) + cost;
                    pq.push({-dist[ny][nx], {ny, nx}});
                }
            }
        }
    }
    return;
}

int main()
{
    memset(k, 0, sizeof(k));
    scanf("%d %d %d %d", &n, &m, &t, &d);
    getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1c", &arr[i][j]);
        }
        getchar();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mountain[i][j] = (int(arr[i][j] - 'a') < 0 ? int(arr[i][j] - 'A') : int(arr[i][j] - 'a' + 26));
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            proc(i, j);
            k[i][j] = dist[0][0];
        }
    }
    proc(0, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            k[i][j] += dist[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //printf("%d ", k[i][j]);
            if (k[i][j] <= d)
            {
                ans = max(ans, mountain[i][j]);
            }
        }
        //printf("\n");
    }

    printf("%d\n", ans);

    return 0;
}