#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<string> graph[26][26];
vector<int> indegree, outdegree;

void makeGraph(const vector<string> &words)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            graph[i][j].clear();
        }
    }
    indegree = vector<int>(26, 0), outdegree = vector<int>(26, 0);
    adj = vector<vector<int>>(26, vector<int>(26, 0));
    for (auto &p : words)
    {
        int len = p.length();
        int a = int(p[0] - 'a');
        int b = int(p[len - 1] - 'a');
        graph[a][b].push_back(p);
        adj[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
}

void getEulerCircuit(int here, vector<int> &circuit)
{
    for (int there = 0; there < adj.size(); there++)
    {
        while (adj[here][there])
        {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

vector<int> CircuitorTrail()
{

    vector<int> circuit;
    for (int i = 0; i < 26; i++)
    {
        if (outdegree[i] == indegree[i] + 1)
        {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (outdegree[i])
        {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    return circuit;
}

bool checkEuler()
{
    int plus = 0, minus = 0;
    for (int i = 0; i < 26; i++)
    {
        plus += (outdegree[i] - indegree[i] == 1) ? 1 : 0;
        minus += (outdegree[i] - indegree[i] == -1) ? 1 : 0;
    }
    if (plus == 1 && minus == 1)
        return true;
    else if (plus == 0 && minus == 0)
        return true;
    return false;
}

string proc(const vector<string> &words)
{
    makeGraph(words);
    if (!checkEuler())
    {
        return "IMPOSSIBLE";
    }
    vector<int> circuit = CircuitorTrail();
    if (circuit.size() != words.size() + 1)
    {
        return "IMPOSSIBLE";
    }
    string ret = "";
    reverse(circuit.begin(), circuit.end());
    int len = circuit.size();
    for (int i = 0; i < len - 1; i++)
    {
        ret += graph[circuit[i]][circuit[i + 1]].back();
        ret += " ";
        graph[circuit[i]][circuit[i + 1]].pop_back();
    }
    return ret;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<string> words;
    cin >> n;
    string x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        words.push_back(x);
    }
    cout << proc(words) << '\n';

    return 0;
}