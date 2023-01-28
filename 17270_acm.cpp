#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int v,m,a,b,c,j,s;
vector<pair<int,int>> adj[101];
vector<int> ans;
int dist[101][101];
bool check[101];

bool comp(pair<int,int> &a, pair<int,int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void floyd(){

  for(int k = 1; k <= v; k++){
    for(int i = 1; i <= v; i++){
      for(int j = 1; j <= v; j++){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  /*
  for(int i = 1; i <= v; i++){
    for(int j = 1; j <= v; j++){
      cout<<dist[i][j]<<" ";
    }cout<<'\n';
  }
  */
  return;
}
/*
void dfs(int here){
  if(here == j) return;
  for(auto &p: adj[here]){
    int cost = p.second, there = p.first;
    if(dist[j][there] + dist[there][s] == dist[s][j] && !check[there]){
      check[there] = true;
      ans.push_back(there);
      dfs(there);
    }
  }
  return;
}
*/

int main(){


  cin>>v>>m;
  for(int i = 1; i <= v; i++){
    for(int j = 1; j <= v; j++){
      if(i!=j) dist[i][j] = MAX;
      else dist[i][j] = 0;
    }
  }
  for(int i = 0 ; i < m; i++){
    cin>>a>>b>>c;
    dist[a][b] = min(dist[a][b],c);
    dist[b][a] = min(dist[b][a],c);
  }
  for(int i = 1; i < v; i++){
    for(int j = i+1; j <= v; j++){
      if(dist[i][j] != MAX){
        adj[i].push_back({j,dist[i][j]});
        adj[j].push_back({i,dist[j][i]});
      }
    }
  }

  cin>>j>>s;
  floyd();
  //dfs(s);
  for(int i = 1; i <= v; i++){
    if(i != s && i != j && dist[j][i] + dist[i][s] == dist[j][s]){
      ans.push_back(i);
    }
  }
  vector<pair<int,int>> ans1;
  for(auto &p: ans){
    if(dist[j][p] <= dist[s][p]){
      ans1.push_back({dist[j][p],p});
    }
  }

  if(ans1.size()>=2){
    sort(ans1.begin(),ans1.end(),comp);
    //for(auto &p : ans1) cout<<p.second<<'\n';
  }
  if(ans1.size()){
    cout<<ans1[0].second<<'\n';
  }else
    cout<<-1<<'\n';


  return 0;
}
