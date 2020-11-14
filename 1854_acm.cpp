#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, k, a, b, c;
vector<pair<int, int>> adj[1001];
priority_queue<int> dist[1001];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1].push(0);
    while (!pq.empty())
    {
        auto t = pq.top();
        int cost = -t.first;
        int here = t.second;
        pq.pop();
        for (auto p : adj[here])
        {
            int to = p.first;
            int weight = p.second;
            if (dist[to].size() < k)
            {
                dist[to].push(cost + weight);
                pq.push({-1 * (cost + weight), to});
            }
            else if (dist[to].top() > cost + weight)
            {
                dist[to].pop();
                dist[to].push(cost + weight);
                pq.push({-1 * (cost + weight), to});
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        if (dist[i].size() != k)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << dist[i].top() << '\n';
        }
    }

    return 0;
}