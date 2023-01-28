#include<bits/stdc++.h>
#define INF 100000000000000LL
using namespace std;

typedef long long ll;
int n,m,u,v,d;
ll dist1[4002],dist2[4002][2];
vector<pair<int,int>> edge[4002];

void dijkstra(){
  for(int i=2;i<=n;i++) dist1[i] = INF;
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
  pq.push({0,1});
  while(!pq.empty()){
    auto t = pq.top();
    pq.pop();
    ll cost=t.first;
    int target=t.second;
    if(cost>dist1[target]) continue;
    for(auto &p:edge[target]){
      int next=p.first, next_cost=p.second;
      if(dist1[target]+next_cost<dist1[next]){
        dist1[next]=dist1[target]+next_cost;
        pq.push({dist1[next],next});
      }
    }
  }
}

void proc(){
  for(int i=2;i<=n;i++){
    for (int j=0;j<=1;j++){
      dist2[i][j] = INF;
    }
  }
  priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> pq;
  pq.push({0,{1,1}});
  while(!pq.empty()){
    auto t =pq.top();
    pq.pop();
    ll cost=t.first;
    int bi=t.second.first,target=t.second.second;
    if(cost>dist2[target][bi]) continue;
    for(auto &p:edge[target]){
      int next=p.first,edge_cost=p.second;
      if(bi&1){
        if(dist2[target][1]+(edge_cost>>1LL)<dist2[next][0]){
          dist2[next][0]=dist2[target][1]+(edge_cost>>1LL);
          pq.push({dist2[next][0],{0,next}});
        }
      }else{
        if(dist2[target][0]+(edge_cost<<1LL)<dist2[next][1]){
          dist2[next][1]=dist2[target][0]+(edge_cost<<1LL);
          pq.push({dist2[next][1],{1,next}});
        }
      }
    }
  }
}


int main(){

  ios_base::sync_with_stdio(0);
  cins.tie(0);
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>u>>v>>d;
    edge[u].push_back({v,2*d});
    edge[v].push_back({u,2*d});
  }
  dijkstra();
  proc();
  int ans=0;
  for(int i=2;i<=n;i++){
    if(dist1[i]<min<ll>(dist2[i][0],dist2[i][1])) ans++;
  }
  cout<<ans<<'\n';

  return 0;
}
