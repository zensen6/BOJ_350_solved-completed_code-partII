#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

bool check[501] = {false};
bool visit[501][501];
int dist[501];
int n, m, s, d, u, v, p;

struct Edge
{
    int to, cost;
};

vector<Edge> r[501];
vector<Edge> e[501];

void dfs(int start, int end)
{

    if (start == end)
    {
        return;
    }
    for (auto &p : r[start])
    {
        if (dist[p.to] == dist[start] - p.cost)
        {
            visit[p.to][start] = true;
            dfs(p.to, end);
        }
    }
    return;
}

void dijkstra(int s, int d)
{

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        dist[i] = MAX;
    }
    dist[s] = 0;
    memset(check, false, sizeof(check));

    pq.push({0, s});
    while (!pq.empty())
    {
        auto t = pq.top();
        int se = t.second;
        int cost = -t.first;
        pq.pop();
        if (check[se])
            continue;
        check[se] = true;
        for (auto &p : e[se])
        {
            if (dist[p.to] > cost + p.cost && !visit[se][p.to])
            {
                dist[p.to] = cost + p.cost;
                pq.push({-dist[p.to], p.to});
            }
        }
    }
    return;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        for (int i = 0; i < 501; i++)
        {
            e[i].clear();
            r[i].clear();
        }

        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        cin >> s >> d;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> p;
            e[u].push_back({v, p});
            r[v].push_back({u, p});
        }

        memset(visit, false, sizeof(visit));
        dijkstra(s, d);
        dfs(d, s);
        dijkstra(s, d);
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<visit[i][j]<<" ";
            }
            cout<<'\n';
        }*/
        if (dist[d] == MAX)
        {
            cout << -1 << '\n';
        }
        else
            cout << dist[d] << '\n';
    }

    return 0;
}