#include <bits/stdc++.h>
using namespace std;

int tc, n;
vector<string> v;
int adj[26][26];
vector<int> ans;
bool check[26];

void sorting()
{
    int len = v.size();
    for (int i = 0; i < len - 1; i++)
    {
        int min_len = min(v[i].length(), v[i + 1].length());
        for (int j = 0; j < min_len; j++)
        {
            if (v[i][j] != v[i + 1][j])
            {
                adj[int(v[i][j] - 'a')][int(v[i + 1][j] - 'a')] = 1;
                break;
            }
        }
    }
    return;
}

void dfs(int here)
{
    check[here] = true;
    for (int i = 0; i < 26; i++)
    {
        if (!check[i] && adj[here][i])
        {
            dfs(i);
        }
    }
    ans.push_back(here);
    return;
}

vector<int> solve()
{
    vector<int> ans_;
    for (int i = 0; i < 26; i++)
    {
        if (!check[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());

    int len = ans.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (adj[ans[j]][ans[i]])
            {
                return vector<int>();
            }
        }
    }

    ans_.assign(ans.begin(), ans.end());
    return ans_;
}

int main()
{
    cin >> tc;
    while (tc--)
    {
        memset(check, false, sizeof(check));
        memset(adj, 0, sizeof(adj));

        string x;
        ans.clear();
        v.clear();

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        sorting();

        vector<int> ans__ = solve();
        if (ans__.size() == 0)
            cout << "IMPOSSIBLE" << '\n';
        else
        {
            for (auto &p : ans__)
            {
                cout << char(p + 'a');
            }
            cout << '\n';
        }
    }

    return 0;
}