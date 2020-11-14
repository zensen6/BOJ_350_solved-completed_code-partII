#include <bits/stdc++.h>
#define x first;
#define y second;
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;
int n, m, a, b, c, dist[1001], arr[1001][1001];
bool check[1001];
vector<pii> adj[1001], ans;

function<void()> f = []() { memset(check, false, sizeof(false)); return; };

void dijkstra()
{
    for (int i = 0; i < 1001; i++)
        dist[i] = INF;
    dist[1] = 0;
    priority_queue<pii> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int cost = -p.x;
        int here = p.y;
        if (cost > dist[here])
            continue;
        for (auto &v : adj[here])
        {
            int to = v.x;
            int w = v.y;
            if (dist[to] > cost + w)
            {
                dist[to] = cost + w;
                pq.push({-dist[to], to});
            }
        }
    }
    return;
}

void dfs(int here, int sum)
{
    check[here] = true;
    for (auto &p : adj[here])
    {
        int to = p.x;
        int w = p.y;
        if (dist[to] == sum + w && !check[to])
        {
            ans.push_back({here, to});
            dfs(to, sum + w);
        }
    }
}

int main()
{
    memset(arr, 0, sizeof(arr));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (!arr[a][b])
        {
            arr[a][b] = c;
            arr[b][a] = c;
        }
        else
        {
            arr[a][b] = min(arr[a][b], c);
            arr[b][a] = min(arr[b][a], c);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j])
            {
                adj[i].push_back({j, arr[i][j]});
            }
        }
    }
    dijkstra();
    f();
    dfs(1, 0);
    cout << ans.size() << '\n';
    for (auto &p : ans)
    {
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}