#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vec;
int n, m, k, sx, sy, ex, ey;
int nx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, ny[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int c[1005][1005], d[1005][1005], INF = 1e9;
pi tr[1000005];

queue<pair<pi, int>> q2;
priority_queue<pair<int, pi>> q;

int dist(pi x, pi y)
{
    return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y);
}

int dijkstra()
{

    int ans = 0;
    q.push({d[sx][sy], {sx, sy}});
    while (!q.empty())
    {
        int cost = q.top().x;
        int x = q.top().y.x, y = q.top().y.y;
        q.pop();
        if (c[x][y])
            continue;
        c[x][y] = 1;
        if (x == ex && y == ey)
        {
            ans = cost;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = x + nx[i], dy = y + ny[i];
            if (dx < 1 || dx > n || dy < 1 || dy > m || c[dx][dy])
                continue;
            q.push({min(cost, d[dx][dy]), {dx, dy}});
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;
    cin >> k;

    memset(c, 0, sizeof(c));
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        tr[i] = {x, y};
        q2.push({{x, y}, i});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            d[i][j] = INF;
    }
    while (!q2.empty())
    {
        int x = q2.front().x.x, y = q2.front().x.y, wi = q2.front().y;
        q2.pop();
        if (d[x][y] <= dist({x, y}, tr[wi]))
            continue;
        d[x][y] = dist({x, y}, tr[wi]);
        for (int i = 0; i < 8; i++)
        {
            int dx = x + nx[i], dy = y + ny[i];
            if (dx < 1 || dx > n || dy < 1 || dy > m)
                continue;
            q2.push({{dx, dy}, wi});
        }
    }
    cout << dijkstra() << '\n';
    /*
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << '\n';
    }
    */

    return 0;
}
