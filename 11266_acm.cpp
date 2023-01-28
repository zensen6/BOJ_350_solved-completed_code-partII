#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;

int v,e,x,y,discovered[10001],counter=0;
set<int> ans;
vector<int> adj[10001];

int proc(int here, bool root){
  int len=adj[here].size(), child=0;
  discovered[here] = counter++;
  int ret = discovered[here];
  for(int i=0;i<len;i++){
    int next = adj[here][i];
    if(discovered[next]==-1){
      child++;
      int subret = proc(next,false);
      if(!root && subret>=discovered[here]){
        ans.insert(here);
      }
      ret = min(ret,subret);
    }else{
      ret = min(ret,discovered[next]);
    }
  }
  if(root && child>=2) ans.insert(here);
  return ret;
}


int main(){

  memset(discovered,-1,sizeof(discovered));
  cin>>v>>e;
  for(int i=0;i<e;i++){
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
  }
  for(int i=1;i<=v;i++)
    if(discovered[i]==-1)
      proc(i,true);
  cout<<ans.size()<<'\n';
  if(ans.size()){

      for(auto &p: ans) cout<<p<<" ";
  }


  return 0;
}
