#include<bits/stdc++.h>
using namespace std;

set<int> s;
int n,m,x,y,u,v;
vector<int> node[1001], candidate;
bool check[1001][1001]; // position, count
void bfs(int count){
    queue<pair<int,int>> q;
    q.push({x,count});
    check[x][count] = true;
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        int next = f.first, c = f.second;
        if(c == 0) candidate.push_back(next);
        for(auto &p:node[next]){
            if(!check[p][c-1]){
                check[p][c-1] = true; 
                q.push({p,c-1});
            }
        }
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>x>>y;    
    for(int i =0;i<m;i++){
        cin>>u>>v;
        node[u].push_back(v);
        node[v].push_back(u);
        s.insert(u);
        s.insert(v);
    }
    bfs(y);
    
    if(s.find(x) == s.end()) cout<<-1;
    else{
        candidate.erase(unique(candidate.begin(),candidate.end()),candidate.end());
        sort(candidate.begin(),candidate.end());
        for(auto &p:candidate) cout<<p<<" ";
    }
    return 0;
}