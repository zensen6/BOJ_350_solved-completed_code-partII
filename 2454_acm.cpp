#include<bits/stdc++.h>
using namespace std;

int n,k,u,v,root=300000,ans=0;
vector<int>node[300001],child[300001];
int groupsize[300001],arr[300001];
bool check[300001];

void root_terminal(int root){
  int i = 0;
  queue<int> q;
  check[root] = true;
  groupsize[root] = 1;
  q.push(root);
  while(!q.empty()){
    auto here = q.front();
    q.pop();
    arr[i++] = here;
    for(auto &c: node[here]){
      if(!check[c]){
        check[c] = true;
        groupsize[c] = 1;
        q.push(c);
        child[here].push_back(c);
      }
    }
  }
  return;
}

int main(){

  memset(child,0,sizeof(child));
  memset(arr,0,sizeof(arr));
  memset(check, false, sizeof(check));
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>k;
  for(int i = 0 ; i < n-1; i++){
    cin>>u>>v;
    root = min(root,u);
    root = min(root,v);
    node[u].push_back(v);
    node[v].push_back(u);
  }
  root_terminal(root);

  for(int i = n-1; i>=0; i--){
    int u = arr[i];
    if(!groupsize[u]) continue;
    vector<pair<int,int>> cb;
    for(auto &p: child[u]){
      if(groupsize[p]) cb.push_back({groupsize[p],p});
    }
    sort(cb.begin(),cb.end());
    int start = 0, cb_size = cb.size();
    while(start<cb_size){
      if(start==2) break;
      if(groupsize[u] + cb[start].first > k+1) break;
      groupsize[u] += cb[start++].first;
    }
    if(start==2){
      groupsize[u] = 0;
      ans++;
    }
    ans += (cb_size-start);
  }
  if(groupsize[root]) ans++;
  cout<<ans<<'\n';

  return 0;
}
