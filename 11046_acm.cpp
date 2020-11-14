#include <bits/stdc++.h>
using namespace std;

int A[2000010], n, t, s, e, num;
int x[2000010];

void manacher(int len)
{
    int r = 0, p = 0;
    for (int i = 0; i < len; i++)
    {
        if (r >= i)
            A[i] = min(r - i, A[2 * p - i]);
        else
            A[i] = 0;
        while ((i - A[i] - 1 >= 0) && (i + A[i] + 1 < len) && (x[i - A[i] - 1] == x[i + A[i] + 1]))
            A[i]++;
        if (i + A[i] > r)
        {
            p = i;
            r = i + A[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        x[c++] = -1;
        cin >> num;
        x[c++] = num;
    }
    x[c++] = -1;
    int len = c;
    manacher(len);
    cin >> t;

    while (t--)
    {
        cin >> s >> e;
        if (A[e + s - 1] * 2 + 1 >= (2 * e - 2 * s + 1 + 2))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}