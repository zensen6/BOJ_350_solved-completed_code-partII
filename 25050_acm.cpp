#include<bits/stdc++.h>
#define INF 1000000000000000LL
using namespace std;

typedef long long ll;
int n,m;
ll d[5001], dist[2001][2001];
vector<pair<ll,ll>> adj[2001];

map<pair<int,int>,int> ma_;

bool dfs(int here, int start, int target){
  if(here==target){
    return true;
  }
  for(auto &p:adj[here]){
    int next=p.first, cost=p.second;
    if(dist[start][next]==dist[start][here]+cost && dfs(next,start,target)){
      d[ma_[here][next]]++;
    }
  }
  return false;
}

void dijkstra(int here){
  dist[here][here] = 0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,here});
  while(!pq.empty()){
    auto t=pq.top();
    pq.pop();
    int cur=t.first, cost=t.second;
    if(cost > dist[here][cur]) continue;
    for(auto &p:adj[cur]){
      int next=p.first;
      cost=p.second;
      if(dist[here][cur]+cost<dist[here][next]){
        dist[here][next]=dist[here][cur]+cost;
        pq.push({dist[here][next],next});
      }
    }
  }
  for(int target=1;target<=n;target++){
    if(target!=here && dist[here][target]!=INF){
      dfs(here,here,target);
    }
  }
  return;
}

int main(){
  int edge_num=1;
  for(int i=0;i<2001;i++){
    for(int j=0;j<2001;j++){
      dist[i][j] = INF;
    }
  }
  cin>>n>>m;
  ll f,t,c;
  for(int i=0;i<m;i++){
    cin>>f>>t>>c;
    ma_[{f,t}] = edge_num++;
    adj[f].push_back({t,c});
  }
  for(int v=1;v<=n;v++){
    dijkstra(v);
  }
  vector<pair<int,int>> ans;
  



  return 0;
}
