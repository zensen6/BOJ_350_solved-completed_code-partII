#include <bits/stdc++.h>
#define INF 10000000000000000ULL
using namespace std;

typedef unsigned long long ll;
ll n, m, a, b, c, s, t, cost;
vector<pair<ll, ll>> adj[100001];
vector<ll> cost_arr;
ll dist[100001];

bool proc(ll maximum)
{

    //memset(check, false, sizeof(check));
    for (int i = 1; i <= 100000; i++)
        dist[i] = INF;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[a] = 0;
    pq.push({0, a});
    while (!pq.empty())
    {
        auto k = pq.top();
        pq.pop();
        ll here = k.second;
        ll cost_ = k.first;
        if (cost_ > dist[here])
            continue;
        if (here == b)
            break;
        for (auto p : adj[here])
        {
            ll next = p.first;
            cost_ = p.second;
            if (dist[here] + cost_ < dist[next] && cost_ <= maximum)
            {
                dist[next] = dist[here] + cost_;
                pq.push({dist[next], next});
            }
        }
    }
    if (dist[b] <= c)
        return true;
    return false;
}

int main()
{

    cin >> n >> m >> a >> b >> c;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> t >> cost;
        adj[s].push_back({t, cost});
        adj[t].push_back({s, cost});
        cost_arr.push_back(cost);
    }
    sort(cost_arr.begin(), cost_arr.end());
    int start = 0, end = cost_arr.size() - 1, mid = (start + end) / 2;
    vector<ll> ans;

    while (start <= end)
    {
        if (start == end)
        {
            if (proc(cost_arr[start]))
            {
                cout << cost_arr[start] << '\n';
            }
            else if (ans.size())
            {
                sort(ans.begin(), ans.end());
                cout << ans[0] << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
            return 0;
        }
        if (proc(cost_arr[mid]))
        {
            ans.push_back(cost_arr[mid]);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }

    if (ans.size())
    {
        sort(ans.begin(), ans.end());
        cout << ans[0] << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}
