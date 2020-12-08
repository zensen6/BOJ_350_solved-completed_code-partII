#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, int> m_;
vector<int> adj[1001];
int match[2002];
bool check[2002];
int ans = 0;

bool dfs(int here)
{

    check[here] = true;
    int len = adj[here].size();
    for (int i = 0; i < len; i++)
    {
        if (match[adj[here][i]] == -1 || (!check[match[adj[here][i]]] && dfs(match[adj[here][i]])))
        {
            match[adj[here][i]] = here;
            match[here] = adj[here][i];
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(match, -1, sizeof(match));
    memset(check, false, sizeof(check));
    string x;
    int c = 1000, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        m_[x] = c++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> x;
            adj[i].push_back(m_[x]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (match[i] == -1)
        {
            memset(check, false, sizeof(check));
            if (dfs(i))
                ans++;
        }
    }
    if (ans == n)
        cout << "YES" << '\n';
    else
    {
        cout << "NO" << '\n';
        cout << ans << '\n';
    }

    return 0;
}