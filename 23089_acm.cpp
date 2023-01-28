#include<bits/stdc++.h>
using namespace std;

int n,k,u,v;
int d[100001][21], a[100001][21], parent[100001],ind[100001];
vector<int> adj[100001];
bool check[100001];

int main(){

  memset(parent,0,sizeof(parent));
  memset(check, false, sizeof(check));
  memset(d,0,sizeof(d));
  memset(a,0,sizeof(a));
  memset(ind,0,sizeof(ind));
  cin>>n>>k;
  for(int i = 0; i < n-1; i++){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  check[1] = 1;
  queue<int> q;
  q.push(1);
  while(!q.empty()){
    auto here = q.front();
    q.pop();
    for(auto &p: adj[here]){
      if(!check[p]){
        ind[here]++;
        parent[p] = here;
        check[p] = true;
        q.push(p);
      }
    }
  }
  vector<int> terminal;
  queue<int> backpropagation;
  for(int i = 1; i <= n; i++){
    if(!ind[i]) terminal.push_back(i);
    a[i][0] = 1;
  }
  for(int u = 1; u <= n; u++){
    for(int k_ = 0; k_ <= k; k_++){
      d[u][k_] = 1;
    }
  }
  for(int k_ = 0; k_ <= k; k_++){
    for(auto &p: terminal){
      d[p][k_] = 1;
    }
  }
  for(auto &p: terminal) backpropagation.push(p);
  while(!backpropagation.empty()){
    auto here = backpropagation.front();
    backpropagation.pop();
    for(int k_ = 1; k_ <= k; k_++){
      d[parent[here]][k_] += d[here][k_-1];
    }
    ind[parent[here]]--;
    if(!ind[parent[here]]){
      backpropagation.push(parent[here]);
    }
  }
  for(int u = 1; u <= n; u++){
    a[u][k] = d[u][k];
    int next = u;
    for(int i = 1; i <= k; i++){
      if(next == 0) break;
      if(k-i-1 < 0 && parent[next]){
        a[u][k] += 1;
        break;
      }
      a[u][k] += (d[parent[next]][k-i] - d[next][k-i-1]);
      next = parent[next];
    }
  }
  int ans = 0;
  for(int u = 1; u <= n; u++){
    ans = max(ans,a[u][k]);
  }
  cout<<ans<<'\n';

/*
  for(int u = 1; u <= n; u++){
    cout<<a[u][k]<<" ";
    cout<<'\n';
  }
*/


  return 0;
}
