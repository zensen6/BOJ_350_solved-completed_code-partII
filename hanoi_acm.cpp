#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n, target, c, x, ans = INF;
vector<vector<int>> layer;
map<vector<vector<int>>, int> m;

bool check(vector<vector<int>> &layer)
{
    for (int i = 1; i <= 3; i++)
    {
        if (layer[i].size() >= 2)
            for (int j = 0; j < layer[i].size(); j++)
            {
                if (layer[i][j] < layer[i][j + 1])
                    return false;
            }
    }
    return true;
}

bool finished(vector<vector<int>> &layer)
{
    if (layer[target].size() != n)
        return false;
    for (int i = 0; i < layer[target].size(); i++)
    {
        if (layer[target][i] != n - i)
            return false;
    }
    return true;
}

void proc(int process, int cannot, vector<vector<int>> layer)
{
    if ((m[layer] != -1 && m[layer] != 0 && m[layer] < process) || (process > 0 && m[layer] == -1))
    {
        return;
    }

    if (process > (1 << (n + 1)))
        return;

    if (finished(layer))
    {
        cout << "yes" << '\n';
        ans = min(ans, process);
        m[layer] = ans;
        return;
    }

    for (int from = 1; from <= 3; from++)
    {
        for (int to = 1; to <= 3; to++)
        {
            if ((from != to) && (cannot != from) && (layer[from].size() > 0))
            {
                int t = layer[from].back();
                layer[from].pop_back();
                layer[to].push_back(t);
                if (check(layer))
                {
                    cout << "here " << from << " " << to << " " << process + 1 << "\n";
                    for (int i = 1; i <= 3; i++)
                    {
                        for (auto &p : layer[i])
                            cout << p << " ";
                        cout << '\n';
                    }
                    cannot = to;
                    proc(process + 1, cannot, layer);
                    m[layer] = (m[layer] > 0 ? min(process + 1, m[layer]) : process + 1);
                }
                t = layer[to].back();
                layer[to].pop_back();
                layer[from].push_back(t);
            }
        }
    }
    return;
}

int main()
{

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> target;
    layer = vector<vector<int>>(4, vector<int>());
    for (int i = 1; i <= 3; i++)
    {
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            cin >> x;
            layer[i].push_back(x);
        }
    }
    //cout << finished() << '\n';
    m[layer] = -1;
    proc(0, 0, layer);

    cout << ans << '\n';
}