#include <bits/stdc++.h>
using namespace std;

bool issquare(vector<pair<int, int>> v)
{
    v[1].first -= v[0].first;
    v[1].second -= v[0].second;
    v[2].first -= v[0].first;
    v[2].second -= v[0].second;
    v[3].first -= v[0].first;
    v[3].second -= v[0].second;
    if (v[1].first * v[2].first + v[1].second * v[2].second == 0)
    {
        if (v[1].first + v[2].first == v[3].first && v[1].second + v[2].second == v[3].second)
        {
            if (pow(v[1].first, 2) + pow(v[1].second, 2) == pow(v[2].first, 2) + pow(v[2].second, 2))
            {
                return true;
            }
        }
    }
    if (v[1].first * v[3].first + v[1].second * v[3].second == 0)
    {
        if (v[1].first + v[3].first == v[2].first && v[1].second + v[3].second == v[2].second)
        {
            if (pow(v[1].first, 2) + pow(v[1].second, 2) == pow(v[3].first, 2) + pow(v[3].second, 2))
            {
                return true;
            }
        }
    }
    if (v[2].first * v[3].first + v[2].second * v[3].second == 0)
    {
        if (v[2].first + v[3].first == v[1].first && v[2].second + v[3].second == v[1].second)
        {
            if (pow(v[2].first, 2) + pow(v[2].second, 2) == pow(v[3].first, 2) + pow(v[3].second, 2))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int T, x, y;
    cin >> T;
    while (T--)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < 4; i++)
        {
            cin >> x >> y;
            v.push_back({x, y});
        }
        cout << issquare(v) << '\n';
    }

    return 0;
}