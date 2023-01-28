#include<bits/stdc++.h>

using namespace std;


int n,m,from,to,ind[101],ans[101];
bool check[101], visited[101];
vector<int> edge[101];

int proc(int v){
  int res = 1;
  bool done = false;
  visited[v] = true;
  for(auto& p : edge[v]){
    if(!visited[p]){
      ans[p]++;
      res += proc(p);
      done = true;
    }
  }
  if(!done) return 1;
  return res;
}

int main(){

  memset(ind,0,sizeof(ind));
  memset(ans,0,sizeof(ans));
  memset(check,false,sizeof(check));
  cin>>n;
  cin>>m;
  for(int i = 0; i < m; i++){
    cin>>from>>to;
    edge[from].push_back(to);
    ind[to]++;
  }
  while(1){
    bool done = false;
    for(int v = 1; v <= n; v++){
      memset(visited,false,sizeof(visited));
      if(!ind[v] && !check[v]){
        done = true;
        ans[v] += proc(v);
        for(auto &p: edge[v]){
          ind[p]--;
        }
        check[v] = true;
      }
    }
    if(!done) break;
  }

  for(int i = 1; i <= n; i++){
    cout<<n-ans[i]<<'\n';
  }



  return 0;
}
