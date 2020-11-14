#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;

int d[101][101][101];

int max_(int a, int b, int c)
{
    return max(max(a, b), max(b, c));
}

int main()
{
    cin >> s1;
    cin >> s2;
    cin >> s3;
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();

    memset(d, 0, sizeof(d));

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            for (int k = 1; k <= len3; k++)
            {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                {
                    d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    d[i][j][k] = max_(d[i - 1][j][k], d[i][j - 1][k], d[i][j][k - 1]);
                }
            }
        }
    }
    
    cout << d[len1][len2][len3] << '\n';

    return 0;
}