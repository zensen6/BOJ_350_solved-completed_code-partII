#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    string x;
    cin >> t;
    while (t--)
    {
        cin >> x;
        int k = (int(x[x.length() - 1] - '0') % 10) - 1;
        int len = x.length();
        cout << 10 * k + len * (len + 1) / 2 << '\n';
    }

    return 0;
}