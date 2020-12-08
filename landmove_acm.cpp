#include <bits/stdc++.h>
using namespace std;

bool check[301][301];
int group[301][301];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
int c = 0;
int parent[100000];

vector<pair<int, int>> adj[100000];

bool inrange(int y, int x, int n)
{
    return y >= 0 && y < n && x >= 0 && x < n;
}

void bfs(int y, int x, int h, vector<vector<int>> lands, int n)
{
    queue<pair<int, int>> q;
    check[y][x] = true;
    q.push({y, x});
    group[y][x] = c;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int y_ = t.first;
        int x_ = t.second;
        for (int i = 0; i < 4; i++)
        {
            int ny = y_ + dy[i];
            int nx = x_ + dx[i];
            if (inrange(ny, nx, n))
                if (abs(lands[y_][x_] - lands[ny][nx]) <= h)
                {
                    if (!check[ny][nx])
                    {
                        q.push({ny, nx});
                        group[ny][nx] = c;
                        check[ny][nx] = true;
                    }
                }
        }
    }
    return;
}

void makeEdge(int h, vector<vector<int>> lands, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dir = 2; dir < 4; dir++)
            {
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if (inrange(ny, nx, n))
                {
                    if (group[ny][nx] != group[i][j] && abs(lands[i][j] - lands[ny][nx]) > h)
                    {
                        adj[group[i][j]].push_back({abs(lands[i][j] - lands[ny][nx]), group[ny][nx]});
                        adj[group[ny][nx]].push_back({abs(lands[i][j] - lands[ny][nx]), group[i][j]});
                    }
                }
            }
        }
    }
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
    int x1 = find(x);
    int y1 = find(y);
    if (x1 < y1)
    {
        parent[y1] = x1;
        find(y);
    }
    else
    {
        parent[x1] = y1;
        find(x);
    }
}

int kruscal()
{
    int ret = 0;
    vector<pair<int, pair<int, int>>> Edge;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int u = i;
            int cost = adj[u][j].first;
            int v = adj[u][j].second;
            Edge.push_back({cost, {u, v}});
        }
    }
    sort(Edge.begin(), Edge.end());
    for (int i = 0; i < Edge.size(); i++)
    {
        int cost = Edge[i].first;
        int u = Edge[i].second.first;
        int v = Edge[i].second.second;
        if (find(u) != find(v))
        {
            Union(u, v);
            ret += cost;
        }
    }
    return ret;
}

int solution(vector<vector<int>> land, int height)
{
    int answer = 0;
    memset(check, false, sizeof(check));
    memset(group, 0, sizeof(group));
    int n = land.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!check[i][j])
            {
                bfs(i, j, height, land, n);
                c++;
            }
        }
    }
    memset(check, false, sizeof(check));
    makeEdge(height, land, n);
    if (c == 1)
        return answer = 0;
    for (int i = 0; i < c; i++)
    {
        parent[i] = i;
    }

    return answer = kruscal();
}

int main()
{

    int n, h;
    cin >> n >> h;
    vector<vector<int>> land(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> land[i][j];
        }
    }
    cout << solution(land, h) << '\n';

    return 0;
}