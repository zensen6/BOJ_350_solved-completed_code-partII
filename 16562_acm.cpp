#include <bits/stdc++.h>
using namespace std;

int price[10001], n, m, k, x, y;
int parent[10001];
int ans[10001];
int minprice[10001];

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
    return;
}

int main()
{

    cin >> n >> m >> k;
    int k1 = k;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
        parent[i] = i;
        minprice[i] = 100000000;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        Union(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        ans[find(i)]++;
        minprice[find(i)] = min(minprice[find(i)], price[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] > 0)
        {
            if (k1 < minprice[i])
            {
                cout << "Oh no" << '\n';
                return 0;
            }
            k1 -= minprice[i];
        }
    }
    cout << k - k1 << '\n';
    return 0;
}