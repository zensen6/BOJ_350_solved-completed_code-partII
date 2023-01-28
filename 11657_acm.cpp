#include<bits/stdc++.h>
#define INF 100000000000000LL
using namespace std;

typedef long long ll;

ll n,m, upper[501], reachable[501][501], a,b,c;
vector<pair<int,int>> adj[501];
bool check[501];

void dfs(int here){
  check[here] = true;
  for(auto p: adj[here]){
    reachable[here][p.first] = true;
    if(!check[p.first]){
      dfs(p.first);
    }
  }
  return;
}

int main(){

  memset(reachable, 0, sizeof(reachable));
  for(int i = 1 ; i < 501; i++){
    for(int j = 1 ; j < 501; j++){
      if(i == j){
        reachable[i][j] = 1;
      }
    }
  }
  for(int i = 1; i < 501; i++){
    upper[i] = INF;
  }
  upper[1] = 0;
  cin>>n>>m;
  for(int i = 0 ; i < m; i++){
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
  }
  for(int i = 1; i <= n; i++){
    memset(check,false,sizeof(check));
    dfs(i);
  }

  for(int iter = 0; iter < n-1; iter++){
    //bool updated = false;
    for(int here = 1; here <= n; here++){
      for(auto p: adj[here]){
        int there = p.first, cost = p.second;
        if(upper[here] == INF) continue;
        if(upper[here] + cost < upper[there]){
          upper[there] = upper[here] + cost;
          /*
          updated = true;
          if(iter == n-1 && updated){
            cout<<-1<<'\n';
            return 0;
          }
          */
        }
      }
    }
  }

  for(int here = 1; here <= n; here++){
    for(auto p: adj[here]){
      int there = p.first, cost = p.second;
      if(upper[here] == INF) continue;
      if(upper[here] + cost < upper[there]){

          cout<<-1<<'\n';
          return 0;

      }
    }
  }

  for(int i = 2; i <= n; i++){
    cout<<(upper[i] >= INF? -1:upper[i])<<'\n';
  }


  return 0;
}
