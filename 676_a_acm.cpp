#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tc, a, b, x;
    cin >> tc;
    while (tc--)
    {
        cin >> a >> b;
        x = a & b;
        cout << (a ^ x) + (b ^ x) << '\n';
    }

    return 0;
}