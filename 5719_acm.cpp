#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n, m, s, d, x, y, p;
vector<pair<int, int>> adj[501];
vector<pair<int, int>> rev[501];
int dist[501];
bool check[501];

void proc(bool reve)
{

    if (reve)
    {
        for (int i = 0; i < 501; i++)
        {
            if (rev[i].size())
            {
                adj[i].assign(rev[i].begin(), rev[i].end());
            }
        }
    }
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < 501; i++)
        dist[i] = INF;
    if (reve)
    {
        dist[d] = 0;
        pq.push({0, d});
    }
    else
    {
        dist[s] = 0;
        pq.push({0, s});
    }
    while (!pq.empty())
    {
        auto t = pq.top();
        int here = t.second;
        int cost = -t.first;
        pq.pop();
        if (cost > dist[here])
            continue;
        for (auto p : adj[here])
        {
            if (p.first == -1)
                continue;
            int weight = p.second;
            int to = p.first;
            if (cost + weight < dist[to])
            {
                dist[to] = cost + weight;
                pq.push({-dist[to], to});
            }
        }
    }
    return;
}

void dfs(int here)
{
    if (here == s)
    {
        return;
    }
    check[here] = true;
    for (auto &p : rev[here])
    {
        if (dist[here] - p.second == dist[p.first])
        {
            if (!check[p.first])
            {
                dfs(p.first);
                p.first = -1;
                p.second = -1;
            }
        }
    }
    return;
}

int main()
{

    while (scanf("%d %d", &n, &m) == 2 && (n || m))
    {
        memset(check, false, sizeof(check));
        for (int i = 0; i < 501; i++)
        {
            adj[i].clear();
            rev[i].clear();
        }

        scanf("%d %d", &s, &d);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &x, &y, &p);
            adj[x].push_back({y, p});
            rev[y].push_back({x, p});
        }
        proc(false);
        dfs(d);

        /*
        for (int i = 0; i < n; i++)
        {
            for (auto p : rev[i])
            {
                printf("from:%d  to:%d  cost:%d", i, p.first, p.second);
            }
            printf("\n");
        }
        */

        proc(true);
        if (dist[s] == INF)
        {
            printf("%d\n", -1);
        }
        else
        {
            printf("%d\n", dist[s]);
        }
    }

    return 0;
}