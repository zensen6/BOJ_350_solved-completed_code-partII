#include<bits/stdc++.h>
#define INF 1000000000000000LL
using namespace std;
typedef long long ll;

void bellmanford(int n){ // n: vertex
	ll dist[501];
	vector<pair<int,int>> edge[501];
  for(int i = 1; i <= n; i++) dist[i] = INF;
  dist[1] = 0; // start only from vertex num 1
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

	// printing dist of each vertex num
  for(int i = 2; i <= n; i++){
    if(dist[i] < INF)
      cout<<dist[i]<<'\n';
    else cout<<-1<<'\n';
  }
	return;
}
