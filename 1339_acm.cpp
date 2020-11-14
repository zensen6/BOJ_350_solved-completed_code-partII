#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string x;
vector<string> v;
int alpha_tonum[26];
bool check[26];
ll ans = 0;
int len;

void proc()
{
    ll sum_ = 0;
    for (int i = 0; i < n; i++)
    {
        ll t = 0;
        for (auto p : v[i])
        {
            t *= 10;
            t += alpha_tonum[int(p - 'A')];
        }
        sum_ += t;
    }
    ans = max(ans, sum_);
}

int main()
{

    memset(check, false, sizeof(check));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (auto &p : x)
        {
            check[int(p - 'A')] = true;
        }
        v.push_back(x);
    }
    vector<int> num;
    for (int i = 0; i < 26; i++)
    {
        if (check[i])
        {
            num.push_back(i);
        }
    }
    len = num.size();
    do
    {
        int c = 9;
        for (int i = 0; i < len; i++)
        {
            alpha_tonum[num[i]] = c--;
        }
        proc();

    } while (next_permutation(num.begin(), num.end()));

    cout << ans << '\n';
    return 0;
}