#include<bits/stdc++.h>
#define INF 1000000000000000LL

using namespace std;

typedef long long ll;
int n,m,a,b,c;
ll dist[501];
vector<pair<int,int>> edge[501];

int main(){

  cin>>n>>m;
  for(int i = 0 ; i < m; i++){
    cin>>a>>b>>c;
    edge[a].push_back({b,c});
  }
  for(int i = 1; i <= n; i++) dist[i] = INF;
  dist[1] = 0;
  for(int iter = 0; iter < n; iter++){
    bool updated = false;
    for(int v = 1; v <= n; v++){
      for(auto &p : edge[v]){
        int target = p.first, cost = p.second;
        if(dist[v] == INF) continue;
        if(dist[target] > dist[v] + cost){
          dist[target]  = dist[v] + cost;
          updated = true;
        }
      }
    }
    if(iter == n-1 && updated){
      cout<<-1<<'\n';
      return 0;
    }else if(!updated) break;
  }
  for(int i = 2; i <= n; i++){
    if(dist[i] < INF)
      cout<<dist[i]<<'\n';
    else cout<<-1<<'\n';
  }
  return 0;
}
