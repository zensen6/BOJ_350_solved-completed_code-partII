#include<bits/stdc++.h>
using namespace std;

int n,q,a,b,u,v,root_cycle;

vector<int> node[200001],cycle;
bool check[200001];
int p[200001],indegree[200001],isNotcycle[200001];
map<int,int> group;

void make_cycle(int here){

  queue<int> q;
  for(int i=1;i<=n;i++) if(indegree[i]==1){
    isNotcycle[i]=1;
    q.push(i);
  }
  while(!q.empty()){
    int f = q.front();
    check[f]=true;
    q.pop();
    for(auto &next:node[f]){
      indegree[next]--;
      if(!check[next]&&indegree[next]==1){
        isNotcycle[next]=1;
        q.push(next);
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(!isNotcycle[i]) cycle.push_back(i);
  }
}



void make_tree_from_cycle(int here, int root_cycle){
  check[here]=true;
  for(auto &p:node[here]){
    if(!check[p]&&!group[p]){
      group[p]=root_cycle;
      make_tree_from_cycle(p,root_cycle);
    }
  }
  return;
}



int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>q;
  for(int i=1;i<=n;i++) p[i]=i;
  for(int i=1;i<=n;i++){
    cin>>u>>v;
    node[u].push_back(v);
    node[v].push_back(u);
    indegree[u]++;
    indegree[v]++;
  }
  make_cycle(1);
  memset(check,false,sizeof(check));
  for(auto c:cycle) group[c]=c;
  for(auto c:cycle){
    make_tree_from_cycle(c,c);
  }
  for(int i=1;i<=q;i++){
    cin>>a>>b;
    if(group[a]==group[b]) cout<<1<<'\n';
    else cout<<2<<'\n';
  }

  return 0;
}
