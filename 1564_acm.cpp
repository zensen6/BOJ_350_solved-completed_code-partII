#include <bits/stdc++.h>
#define MOD 100000ULL
using namespace std;

int n;
int main()
{

    cin >> n;
    unsigned long long ans = 1ULL;
    for (int i = 2ULL; i <= n; i++)
    {
        ans *= i;
        while (ans % 10ULL == 0)
            ans /= 10ULL;
        ans %= MOD;
    }
    ans %= MOD;
    if (ans >= 10000)
    {
        cout << ans << "\n";
    }
    else if (ans < 10000 && ans >= 1000)
    {
        cout << "0" << ans << '\n';
    }
    else if (ans < 1000 && ans >= 100)
    {
        cout << "00" << ans << '\n';
    }
    else if (ans < 100 && ans >= 10)
    {
        cout << "000" << ans << '\n';
    }
    else if (ans < 10 && ans >= 0)
    {
        cout << "0000" << ans << "\n";
    }
    return 0;
}