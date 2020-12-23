#include <bits/stdc++.h>
using namespace std;

int m[13][13], arr[13][13], tc, n, k = 1, c = 0;
int ans = 1e9;
vector<pair<int, int>> v;

bool proc(int sy, int sx, int fy, int fx, bool turn)
{
    bool done = true;
    if (sy == fy)
    {
        for (int i = min(sx, fx); i <= max(sx, fx); i++)
        {
            if (turn && arr[sy][i])
                done = false;
            arr[sy][i] = 1 - arr[sy][i];
        }
    }
    else if (sx == fx)
    {
        for (int i = min(sy, fy); i <= max(sy, fy); i++)
        {
            if (turn && arr[i][sx])
                done = false;
            arr[i][sx] = 1 - arr[i][sx];
        }
    }
    return done;
}

void go(int num, int s)
{
    if (num >= c)
    {
        ans = min(ans, s);
        return;
    }
    if (v[num].first == 0 || v[num].second == 0 || v[num].first == n - 1 || v[num].second == n - 1)
    {
        arr[v[num].first][v[num].second] = 1;
        go(num + 1, s);
    }
    else
    {
        if (proc(v[num].first, v[num].second, v[num].first, 0, 1))
        {
            go(num + 1, s + v[num].second);
        }
        proc(v[num].first, v[num].second, v[num].first, 0, 0);

        if (proc(v[num].first, v[num].second, 0, v[num].second, 1))
        {
            go(num + 1, s + v[num].first);
        }
        proc(v[num].first, v[num].second, 0, v[num].second, 0);

        if (proc(v[num].first, v[num].second, v[num].first, n - 1, 1))
        {
            go(num + 1, s + (n - 1) - v[num].second);
        }
        proc(v[num].first, v[num].second, v[num].first, n - 1, 0);

        if (proc(v[num].first, v[num].second, n - 1, v[num].second, 1))
        {
            go(num + 1, s + (n - 1) - v[num].first);
        }
        proc(v[num].first, v[num].second, n - 1, v[num].second, 0);
    }
    return;
}

int main()
{

    cin >> tc;
    while (tc--)
    {
        v.clear();
        c = 0;
        ans = 1e9;
        memset(arr, 0, sizeof(arr));
        memset(m, 0, sizeof(m));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
                if (m[i][j])
                {
                    c++;
                    v.push_back({i, j});
                }
            }
        }
        go(0, 0);
        cout << "#" << k << " " << ans << '\n';
        ++k;
    }

    return 0;
}
