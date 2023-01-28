#include<bits/stdc++.h>
using namespace std;
int n,x;
vector<int> path;

bool impossible=false;
int edgeNum = 0;
vector<int> adj[1001];
pair<int,int> edge[1000001];
int edgeCount[1000001];

void dfs(int here){
  while(adj[here].size()){
    int edgeN = adj[here].back();
    auto e = edge[edgeN];
    int u = e.first, v = e.second;
    if(edgeCount[edgeN]){
      edgeCount[edgeN]--;
      if(here==u){
        dfs(v);
      }else{
        dfs(u);
      }
    }
    else adj[here].pop_back();
  }
  path.push_back(here);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int s=0;
    for(int j=0;j<n;j++){
      cin>>x;
      s+=x;
      if(x && (j>i)){
        adj[i].push_back(edgeNum);
        adj[j].push_back(edgeNum);
        edgeCount[edgeNum] += x;
        edge[edgeNum++] = {i,j};
      }
    }
    if(s&1){
      impossible=true;
    }
  }
  if(impossible){
    cout<<-1<<'\n';
    return 0;
  }
  dfs(0);
  for(auto &p:path) cout<<p+1<<" ";


  return 0;
}
