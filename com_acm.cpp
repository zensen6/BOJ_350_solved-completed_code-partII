#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    for (auto &p : participant)
    {
        m[p]++;
    }
    for (auto &p : completion)
    {
        m[p]--;
    }
    map<string, int>::iterator it_;
    for (it_ = m.begin(); it_ != m.end(); it_++)
    {
        if (((*it_).second))
        {
            answer = (*it_).first;
        }
    }

    return answer;
}
int main()
{
    int n;
    vector<string> participant, completion;
    string x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        participant.push_back(x);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        completion.push_back(x);
    }

    string y = solution(participant, completion);
    cout << y << '\n';
}
