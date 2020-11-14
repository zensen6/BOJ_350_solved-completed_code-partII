#include <bits/stdc++.h>
using namespace std;

int n, m;
bool notprime[1000010];

int main()
{
    cin >> n >> m;
    memset(notprime, false, sizeof(notprime));
    notprime[1] = true;

    for (int i = 2; i * i <= m; i++)
    {
        if (!notprime[i])
        {
            for (int j = i * i; j <= m; j += i)
            {
                notprime[j] = true;
            }
        }
    }
    for (int i = n; i <= m; i++)
    {
        if (!notprime[i])
            cout << i << "\n";
    }

    return 0;
}