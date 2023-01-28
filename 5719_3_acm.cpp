#include<bits/stdc++.h>
#define MAX 2000000000
using namespace std;

int n,m,u,v,p,s,d;
vector<pair<int,int>> adj[501], rev[501];
int dist[501], check[501], edge[501][501];


void dijkstra(int start, int target){
  for(int i = 0; i < 501;i++) dist[i] = MAX;
  dist[start] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,start});
  while(!pq.empty()){
    auto t = pq.top();
    pq.pop();
    int here = t.second, cost = t.first;
    if(dist[here] < cost) continue;
    for(auto k:adj[here]){
      int cost_ = k.second, next = k.first;
      if(dist[here] + cost_ < dist[next] && edge[here][next] == -1){
        dist[next] = dist[here] + cost_;
        pq.push({dist[next],next});
      }
    }
  }
}

void backdfs(int here){
  check[here] = 1;
  for(auto& k: rev[here]){
    if(check[k.first] == -1 && dist[here] - k.second == dist[k.first]){
      edge[k.first][here] = 1;
      backdfs(k.first);
    }
  }
  return;
}

int main(){

  while(1){
    memset(edge,-1,sizeof(edge));
    memset(check,-1,sizeof(check));
    for(int i = 0 ; i < 501; i++){
      adj[i].clear();
      rev[i].clear();
    }
      cin>>n>>m;
      if(n==0&&m==0) break;
      cin>>s>>d;
      for(int i = 0 ; i < m; i++){
        cin>>u>>v>>p;
        adj[u].push_back({v,p});
        rev[v].push_back({u,p});
      }
      dijkstra(s,d);
      //for(int i = 0; i < n; i++) cout<<dist[i]<<'\n';
      backdfs(d);
      dijkstra(s,d);
      if(dist[d] == MAX) cout<<-1<<'\n';
      else cout<<dist[d]<<'\n';

  }

  return 0;
}
