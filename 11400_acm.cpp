#include<bits/stdc++.h>
using namespace std;

int v,e,x,y;
vector<pair<int,int>> edge;
vector<int> adj[100001];
int discovered[100001], counter=0;

bool comp(pair<int,int>&a, pair<int,int>&b){
  if(a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}

int proc(int here, int prev){
  discovered[here] = counter++;
  int ret = discovered[here];
  int len = adj[here].size();
  for(int i=0;i<len;i++){
    int next = adj[here][i];
    if(next == prev) continue;
    if(discovered[next] == -1){
      int subret = proc(next, here);
      if(subret > discovered[here]){
        edge.push_back({min(here,next),max(here,next)});
      }
      ret = min(ret, subret);
    }else{
      ret = min(ret, discovered[next]);
    }
  }
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
  proc(1, -1);
  sort(edge.begin(),edge.end(),comp);
  cout<<edge.size()<<'\n';
  for(auto &[from,to]:edge) cout<<from<<" "<<to<<'\n';


  return 0;
}
