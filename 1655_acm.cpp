#include <bits/stdc++.h>
using namespace std;

int n, x;
priority_queue<int, vector<int>, greater<int>> M;
priority_queue<int> m;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    if (i & 1)
    {
      if (m.size() == 0)
        m.push(x);
      else if (M.top() <= x)
      {
        int y = M.top();
        M.pop();
        M.push(x);
        m.push(y);
      }
      else
        m.push(x);
    }
    else
    {
      if (x >= m.top())
        M.push(x);
      else
      {
        int y = m.top();
        m.pop();
        M.push(y);
        m.push(x);
      }
    }
    cout << m.top() << '\n';
  }

  return 0;
}
