#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int n,m,x,y,c;
int dist[101][101];
int via[101][101];
vector<int> path[101][101];

void proc(int from, int to, vector<int> &v){
  if(via[from][to] == 0) return;
  int k = via[from][to];
  proc(from, k, v);
  v.push_back(k);
  proc(k, to, v);
  return;
}


int main(){

  for(int i=0;i<101;i++){
    for(int j=0;j<101;j++){
      dist[i][j] = MAX;
    }
  }

  cin>>n;
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>x>>y>>c;
    dist[x][y] = min(dist[x][y], c);
  }

  for(int i=1;i<=n;i++){
    dist[i][i] = 0;
  }

  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(dist[i][k] + dist[k][j] < dist[i][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          if(i != j) via[i][j] = k;
        }
      }
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(dist[i][j] == MAX) cout<<0<<" ";
      else cout<<dist[i][j]<<" ";
    }
    cout<<'\n';
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j) cout<<0<<'\n';
      else{
        path[i][j].push_back(i);
        proc(i,j,path[i][j]);
        path[i][j].push_back(j);
        //reverse(path[i][j].begin(),path[i][j].end());
        if(dist[i][j] == MAX) cout<<0<<'\n';
        else{
          cout<<path[i][j].size()<<" ";
          for(auto &p:path[i][j]) cout<<p<<" ";
          cout<<'\n';
        }
      }
    }
  }



  return 0;
}
