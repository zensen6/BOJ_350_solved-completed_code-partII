#include <bits/stdc++.h>
using namespace std;

bool iscorrect(string x)
{
    int l = 0, r = 0;
    for (auto &p : x)
    {
        if (p == '(')
        {
            l++;
        }
        else
        {
            r++;
            if (r > l)
                return false;
        }
    }
    return l == r ? true : false;
}
string returnu(string x)
{
    int l = 0, r = 0;
    string ans = "";
    for (auto &p : x)
    {
        if (p == '(')
        {
            l++;
            ans += "(";
        }

        else
        {
            r++;
            ans += ")";
        }

        if (l == r)
            return ans;
    }
    return ans;
}

string reverseu(string u)
{
    string ans = "";
    int len = u.length();
    for (int i = 1; i < len - 1; i++)
    {
        if (u[i] == '(')
            ans += ")";
        else
            ans += "(";
    }
    return ans;
}

string proc(string p)
{
    if (p == "")
        return "";
    string ans = "";
    string u = returnu(p);
    int len_u = u.length();
    string v = p.substr(len_u);
    if (iscorrect(u))
    {
        ans = u;
        v = proc(v);
        ans += v;
    }
    else
    {
        ans += "(";
        v = proc(v);
        ans += v;
        ans += ")";
        ans += reverseu(u);
    }

    return ans;
}

string solution(string p)
{
    string answer = "";
    answer = proc(p);

    return answer;
}

int main()
{
    string x;
    cin >> x;
    cout << solution(x) << '\n';
    return 0;
}