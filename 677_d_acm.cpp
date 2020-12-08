#include <bits/stdc++.h>
using namespace std;
int t, n, x;
map<int, int> v_c;
vector<int> a;
bool check[5002];
void dfs(int index, bool start)
{
    bool done = false;
    check[index] = true;
    for (int i = index + 1; i <= n; i++)
    {
        if (!check[i] && a[index] != a[i])
        {
            done = true;
            check[i] = true;
            cout << index << " " << i << '\n';
            dfs(i, false);
        }
    }
    if (!done && start)
    {
        for (int i = index + 1; i <= n; i++)
        {
            if (a[index] != a[i])
            {
                cout << index << " " << i << '\n';
                break;
            }
        }
    }

    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(check, false, sizeof(check));
        map<int, int> c_c;
        v_c = c_c;
        cin >> n;
        a = vector<int>(n + 2, 0);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            v_c[a[i]]++;
        }

        int max_ = 0;
        for (auto it : v_c)
        {
            max_ = max(it.second, max_);
        }
        if (max_ == n)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
            for (int i = 1; i <= n; i++)
            {
                if (!check[i])
                    dfs(i, 1);
            }
        }
    }
    return 0;
}