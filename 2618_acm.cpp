#include <bits/stdc++.h>

using namespace std;

int n, w, y, x;
vector<pair<int, int>> pos;
int d[1001][1001];
int c[1001][1001];

int dist(int i, int j)
{
    return abs(pos[j].first - pos[i].first) + abs(pos[j].second - pos[i].second);
}

int proc(int index, int last)
{
    if (index == w)
        return 0;
    int &ret = d[index][last];
    if (ret != -1)
        return ret;
    ret = 0;
    int r1 = proc(index + 1, index) + dist(last, index + 1);
    int r2 = proc(index + 1, last) + dist(index + 1, index);
    if (r1 < r2)
    { // change
        c[index][last] = index;
    }
    else
    {
        c[index][last] = last;
    }
    return ret = min(r1, r2);
}

void track(int index, int last, vector<int> &trace)
{

    if (index == w)
    {
        return;
    }

    if (c[index][last] == index)
    {
        trace.push_back(3 - trace.back());
        track(index + 1, index, trace);
    }
    else
    {
        trace.push_back(trace.back());
        track(index + 1, last, trace);
    }
    return;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> w;
    memset(d, -1, sizeof(d));
    memset(c, -1, sizeof(c));
    vector<int> a;
    vector<int> trace;
    pos = vector<pair<int, int>>(w + 1, {0, 0});
    for (int i = 1; i <= w; i++)
    {
        cin >> y >> x;
        pos[i].first = y;
        pos[i].second = x;
    }
    pos[0].first = 1;
    pos[0].second = 1;
    int sub;
    sub = dist(1, 0);
    pos[0].first = n;
    pos[0].second = n;
    int ans1 = proc(1, 0) + sub;

    a.push_back(1);
    track(1, 0, a);

    memset(d, -1, sizeof(d));
    sub = dist(1, 0);
    pos[0].first = 1;
    pos[0].second = 1;
    int ans2 = proc(1, 0) + sub;

    trace.push_back(2);
    track(1, 0, trace);

    if (ans1 < ans2)
    {
        cout << ans1 << '\n';
        for (auto &p : a)
            cout << p << '\n';
    }
    else
    {
        cout << ans2 << '\n';
        for (auto &p : trace)
            cout << p << '\n';
    }
    return 0;
}