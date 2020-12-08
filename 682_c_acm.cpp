#include <bits/stdc++.h>
using namespace std;

int dy[2] = {-1, 0};
int dx[2] = {0, -1};

bool inrange(int y, int x, int n, int m)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int arr[101][101];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int ny, nx;
                bool eq = false;
                for (int d = 0; d < 2; d++)
                {
                    ny = i + dy[d];
                    nx = j + dx[d];
                    if (inrange(ny, nx, n, m))
                    {
                        if (arr[ny][nx] == arr[i][j] + 1)
                        {
                            eq = true;
                        }
                    }
                }
                if (!eq)
                    arr[i][j] += 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}