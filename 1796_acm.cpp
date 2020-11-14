#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

string S;
int alpha[26];
int d[1001][1001];
int sm = 1000, sM = 0, len;
vector<pair<int, int>> range[26];

int dp(int cur, int next)
{
    int &ret = d[cur][next];
    if (ret != -1)
        return ret;

    ret = INF;
    int cur_alpha = int(S[next] - 'a');
    int next_alpha = -1;
    for (int i = cur_alpha + 1; i < 26; i++)
    {
        if (range[i].size() > 0)
        {
            next_alpha = i;
            break;
        }
    }
    if (next_alpha == -1)
        return 0;
    int m = range[next_alpha][0].first;
    int M = range[next_alpha][0].second;

    if (next < m)
    {
        ret = min(ret, dp(next, m) + (M - m) + alpha[next_alpha] + M - next);
        ret = min(ret, dp(next, M) + alpha[next_alpha] + M - next);
    }
    else if (next > M)
    {
        ret = min(ret, dp(next, M) + (M - m) + alpha[next_alpha] + next - m);
        ret = min(ret, dp(next, m) + alpha[next_alpha] + next - m);
    }
    else
    {
        ret = min(ret, dp(next, m) + abs(m - M) + alpha[next_alpha] + abs(M - next));
        ret = min(ret, dp(next, M) + abs(m - M) + alpha[next_alpha] + abs(m - next));
    }

    return ret;
}

int main()
{
    cin >> S;
    len = S.length();
    memset(alpha, 0, sizeof(alpha));
    for (auto &p : S)
        alpha[int(p - 'a')]++;
    memset(d, -1, sizeof(d));

    for (int i = 0; i < 26; i++)
    {
        sm = -1;
        sM = -1;
        for (int j = 0; j < len; j++)
        {
            if (S[j] == char(i + 'a'))
            {
                sm = j;
                break;
            }
        }
        for (int j = len - 1; j >= 0; j--)
        {
            if (S[j] == char(i + 'a'))
            {
                sM = j;
                break;
            }
        }
        if (sm != -1 && sM != -1)
            range[i].push_back({sm, sM});
    }

    int first_alpha;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > 0)
        {
            first_alpha = i;
            break;
        }
    }
    cout << dp(0, range[first_alpha][0].second) + alpha[first_alpha] + range[first_alpha][0].second << '\n';

    return 0;
}