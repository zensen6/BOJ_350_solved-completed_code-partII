#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;


int n,m,s,d,u,v,c;
int dist[501];
vector<pair<int,int>> node[501], rev[501];
bool check[501][501];


int dijkstra(){

  for(int i=0;i<501;i++) dist[i] = MAX;
  dist[s] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0,s});
  while(!pq.empty()){
    auto f = pq.top();
    pq.pop();
    int cost = f.first, target = f.second;
    if(dist[target] < cost) continue;
    for(auto &p:node[target]){
      int cost_ = p.second, next = p.first;
      if(dist[target] + cost_ < dist[next] && !check[target][next]){
        dist[next] = dist[target] + cost_;
        pq.push({dist[next], next});
      }
    }
  }
  return dist[d];
}

void dfs(int here){
  if(here == s) return;
  for(auto &p: rev[here]){
    int cost = p.second, prev = p.first;
    if(!check[prev][here] && dist[here] - cost == dist[prev]){
      check[prev][here] = true;
      dfs(prev);
    }
  }
  return;
}



int main(){

  while(cin>>n>>m){
    if(n == 0 && m == 0) break;
    for(int i=0;i<501;i++){
      node[i].clear();
      rev[i].clear();
    }
    memset(check,false,sizeof(check));
    cin>>s>>d;
    for(int i=0;i<m;i++){
      cin>>u>>v>>c;
      node[u].push_back({v,c});
      rev[v].push_back({u,c});
    }
    dijkstra();
    dfs(d);

    int ret = dijkstra();
    if(ret == MAX){
      cout<<-1<<'\n';
    }else{
      cout<<ret<<'\n';
    }

  }



  return 0;
}
