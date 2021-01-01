#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
vector<pair<string, int>> v;
int k;

int dist(string &a, string &b)
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] != b[i])
            ans++;
    }
    return ans;
}

int solve()
{
    int a = 1e9;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int z = 0; z < k; z++)
            {
                if (v[i].second >= 3)
                {
                    a = 0;
                }
                else if (i == j && j != z && v[i].second == 2)
                    a = min(a, dist(v[i].first, v[z].first) + dist(v[j].first, v[z].first));
                else if (i == z && i != j && v[i].second == 2)
                    a = min(a, dist(v[i].first, v[j].first) + dist(v[z].first, v[j].first));
                else if (j == z && i != j && v[j].second == 2)
                    a = min(a, dist(v[i].first, v[j].first) + dist(v[z].first, v[i].first));
                else if (i != j && j != z && z != i)
                {

                    a = min(a, dist(v[i].first, v[j].first) + dist(v[z].first, v[i].first) + dist(v[z].first, v[j].first));
                }
            }
        }
    }
    return a;
}

int main()
{

    int t, n;
    string x;
    cin >> t;
    while (t--)
    {
        v.clear();
        m.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            m[x]++;
        }
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++)
        {
            v.push_back({(*it).first, (*it).second});
        }
        k = v.size();
        //
        //

        cout << solve() << '\n';
    }

    return 0;
}
