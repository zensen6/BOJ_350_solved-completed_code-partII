#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[10001];
int count_[10001];
bool check[10001];
int k = 0, ans_ = -1;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

void dfs(int here)
{
    k++;
    ans_ = max(ans_, k);
    check[here] = true;
    for (auto &p : adj[here])
    {
        if (!check[p])
        {
            dfs(p);
        }
    }
    return;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        k = 0;
        memset(check, false, sizeof(check));
        dfs(i);
        count_[i] = k;
    }

    //
    //for (int i = 1; i <= n; i++)
    //  cout << count_[i] << " ";
    //
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back({i, count_[i]});
    }
    sort(ans.begin(), ans.end(), comp);
    for (int i = 0; i < n; i++)
    {
        if (ans[i].second != ans_)
            break;
        else
        {
            cout << ans[i].first << " ";
        }
    }
    cout << '\n';
    return 0;
}