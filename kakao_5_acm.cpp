#include <bits/stdc++.h>
using namespace std;

bool inrange(int x, int y, int n)
{
    return x >= 0 && x <= n && y >= 0 && y <= n;
}

bool isok(vector<int> arr[101][101], vector<int> o, int n)
{
    int x = o[0];
    int y = o[1];
    int a = o[2];
    int b = o[3];
    if (b == 1)
    {
        if (a == 0)
        { //기둥
            if (arr[x][y][0] == 4)
                return false;
            arr[x][y + 1].push_back(1);
            sort(arr[x][y + 1].begin(), arr[x][y + 1].end());
        }
        else
        { //보
            if (arr[x][y][0] == 1 || arr[x + 1][y][0] == 1)
            {
                arr[x][y].push_back(2);
                arr[x + 1][y].push_back(2);
            }
            else if (arr[x][y][0] == 2 && arr[x + 1][y][0] == 2)
            {
                //pass
            }
            else
                return false;
        }
    }
    else
    {
        if (a == 0)
        {
            if ((inrange(x - 1, y + 1, n) && arr[x - 1][y + 1][0] == 2) || (inrange(x + 1, y + 1, n) && arr[x + 1][y + 1][0] == 2))
            {
                return false;
            }
            else
            {
                vector<int>::iterator it = arr[x][y].begin();
                arr[x][y].erase(it);
            }
        }
        else
        {
            if (inrange(x + 2, y, n) && arr[x + 2][y][0] == 1)
            {
            }
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    vector<int> arr[101][101];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            arr[i][j].push_back(4);
        }
    }
    for (int i = 0; i <= n; i++)
        arr[i][0].push_back(3);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            sort(arr[i][j].begin(), arr[i][j].end());
        }
    }

    for (auto &p : build_frame)
    {
    }

    return answer;
}

int main()
{
    int n, m, x, y, a, b;
    cin >> n >> m;
    vector<vector<int>> build_frame;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        cin >> x >> y >> a >> b;
        v.push_back(x);
        v.push_back(y);
        v.push_back(a);
        v.push_back(b);
        build_frame.push_back(v);
    }
    vector<vector<int>> ans = solution(n, build_frame);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}