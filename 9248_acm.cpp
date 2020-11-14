#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> group;
vector<int> lcp;

struct Compare2T
{
    int t;
    Compare2T(int t) : t(t) {}
    bool operator()(int i, int j)
    {
        if (group[i] != group[j])
            return group[i] < group[j];
        else
            return group[i + t] < group[j + t];
    }
};

vector<int> SuffixArray(const string &x)
{
    group = vector<int>(n + 1, 0);
    group[n] = -1;
    vector<int> perm(n, 0);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
        group[i] = x[i];
    }
    int t = 1;
    for (;; t *= 2)
    {
        Compare2T comp(t);
        sort(perm.begin(), perm.end(), comp);
        vector<int> newgroup(n + 1, 0);
        newgroup[n] = -1;
        newgroup[perm[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (comp(perm[i - 1], perm[i]))
                newgroup[perm[i]] = newgroup[perm[i - 1]] + 1;
            else
                newgroup[perm[i]] = newgroup[perm[i - 1]];
        }
        group = newgroup;
        if (group[perm[n - 1]] == n - 1)
            break;
    }
    return perm;
}

void makeLCP(vector<int> &perm, const string &x)
{
    lcp = vector<int>(n, 0);
    for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0))
    {
        if (group[i] == n - 1)
            continue;
        for (int j = perm[group[i] + 1]; x[i + k] == x[j + k]; k++)
            ;
        lcp[group[i] + 1] = k;
    }
    return;
}

int main()
{
    string x;
    cin >> x;
    n = x.length();
    vector<int> perm = SuffixArray(x);
    for (auto &p : perm)
        cout << p + 1 << " ";
    cout << '\n';
    cout << "x"
         << " ";

    makeLCP(perm, x);
    for (vector<int>::iterator it = lcp.begin() + 1; it != lcp.end(); it++)
        cout << *it << " ";
    cout << '\n';

    return 0;
}