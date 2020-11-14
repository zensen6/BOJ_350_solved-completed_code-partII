#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int arr[1006][1006];
bool check[1006][1006];
//int dist[1001][1001];
pair<int, int> pos[1000010];
int Wx, Wy, sx, sy, tx, ty, n, x, y;
int dy[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dx[8] = {0, -1, 1, 0, -1, 1, -1, 1};

int dist(int x, int x1, int y, int y1)
{
    return (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
}

bool inrange(int y, int x)
{
    return y > 0 && y <= Wy && x > 0 && x <= Wx;
}

void bfs()
{
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        //arr[pos[i].first][pos[i].second] = 0;
        q.push({{pos[i].first, pos[i].second}, i});
    }
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int cy = p.first.first;
        int cx = p.first.second;
        int w_i = p.second;
        int ny, nx;
        if (dist(pos[w_i].second, cx, pos[w_i].first, cy) >= arr[cy][cx])
            continue;
        arr[cy][cx] = dist(pos[w_i].second, cx, pos[w_i].first, cy);
        for (int i = 0; i < 8; i++)
        {
            ny = cy + dy[i];
            nx = cx + dx[i];
            if (inrange(ny, nx))
            {
                q.push({{ny, nx}, w_i});
            }
        }
    }
    return;
}

int dijkstra()
{
    priority_queue<pair<pair<int, int>, int>> pq;
    pq.push({{sy, sx}, arr[sy][sx]});
    memset(check, false, sizeof(check));
    int ans = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int y = p.first.first, x = p.first.second, w = p.second;
        if (check[y][x])
            continue;
        check[y][x] = true;
        if (y == ty && x == tx)
        {
            ans = w;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inrange(ny, nx) && !check[ny][nx])
            {
                pq.push({{ny, nx}, min(arr[ny][nx], w)});
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 1005; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            arr[i][j] = INF;
        }
    }
    memset(check, false, sizeof(check));
    //memset(dist, 0, sizeof(dist));
    cin >> Wx >> Wy;
    cin >> sx >> sy >> tx >> ty;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pos[i] = {y, x};
    }
    bfs();
    cout << dijkstra() << '\n';

    /*
    for (int i = 0; i <= Wy; i++)
    {
        for (int j = 0; j <= Wx; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    */

    return 0;
}