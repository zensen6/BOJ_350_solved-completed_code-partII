#include <bits/stdc++.h>
#define MAX 100000000000LL
using namespace std;

typedef long long ll;
bool check[542];

ll k, n;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main()
{
    int x;
    cin >> k >> n;
    vector<int> p;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        p.push_back(x);
        pq.push(x);
    }
    int len = p.size(), pop_c = 0, index;
    ll t;
    while (pop_c < n)
    {
        t = pq.top();
        pq.pop();
        pop_c++;
        if (pop_c == n)
            break;
        for (index = len - 1; index >= 0; index--)
        {
            if (t % p[index] == 0)
                break;
        }
        if (index == len - 1)
        {
            pq.push(t * p[index]);
        }
        else
        {
            for (int j = index; j < len; j++)
            {
                pq.push(t * p[j]);
            }
        }
    }
    cout << t << '\n';

    return 0;
}