#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{

    int height = board.size();
    int width = board[0].size();
    vector<int> n_board[width];
    for (int i = 0; i < width; i++)
    {
        for (int j = height - 1; j >= 0; j--)
        {
            if (board[j][i])
            {
                n_board[i].push_back(board[j][i]);
            }
        }
    }
    /*
    for (int i = 0; i < width; i++)
    {
        for (auto &p : n_board[i])
        {
            cout << p << ' ';
        }
        cout << '\n';
    }
    */

    int answer = 0;
    int c = 0;
    vector<int> basket;
    for (auto &p : moves)
    {
        if (n_board[p - 1].size())
        {
            if (basket.size() && basket[basket.size() - 1] == n_board[p - 1].back())
            {
                c++;
                basket.pop_back();
            }
            else
            {
                basket.push_back(n_board[p - 1].back());
            }
            n_board[p - 1].pop_back();
        }
    }

    return answer = 2 * c;
}

int main()
{
    vector<vector<int>> board;
    int n, m;
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    cin >> m;
    vector<int> moves(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> moves[i];
    }
    cout << solution(board, moves) << '\n';
}