#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arrows)
{
    pair<int, int> dir[8] = {{0, 2}, {2, 2}, {2, 0}, {2, -2}, {0, -2}, {-2, -2}, {-2, 0}, {-2, 2}};
    pair<int, int> diag[4] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int answer = 0;
    int len = arrows.size();
    map<pair<int, int>, int> check;
    map<pair<int, pair<int, int>>, int> double_check;
    int x = 0, y = 0;
    check[{0, 0}] = 1;
    const int MOD = 8;
    for (int i = 0; i < len; i++)
    {
        int dx = dir[arrows[i]].first;
        int dy = dir[arrows[i]].second;

        if (double_check[{arrows[i], {x + dx, y + dy}}] == 0)
        {
            if (check[{x + dx, y + dy}])
            {
                answer += 1;
            }
        }

        if (arrows[i] & 1)
        {
            int diag_x = x + diag[arrows[i] / 2].first;
            int diag_y = y + diag[arrows[i] / 2].second;
            if (check[{diag_x, diag_y}] && double_check[{arrows[i], {diag_x, diag_y}}] == 0)
            {
                answer += 1;
            }
            check[{diag_x, diag_y}] = 1;
            double_check[{arrows[i], {diag_x, diag_y}}] = 1;
            double_check[{(arrows[i] + 4) % MOD, {diag_x, diag_y}}] = 1;
        }

        check[{x + dx, y + dy}] = 1;
        double_check[{arrows[i], {x + dx, y + dy}}] = 1;
        double_check[{(arrows[i] + 4) % MOD, {x, y}}] = 1;

        x += dx;
        y += dy;
        //cout << x << " " << y << " " << answer << '\n';
    }

    return answer;
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> arrows;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arrows.push_back(x);
    }
    cout << solution(arrows) << '\n';

    return 0;
}