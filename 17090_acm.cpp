#include<bits/stdc++.h>
using namespace std;

int n,m;
string arr[501];
bool check[501][501];
int already_count[501][501], ind[501][501];

bool inrange(int y,int x){
  return y>=0&&y<n&&x>=0&&x<m;
}

vector<int> v[260000];

void make_graph(pair<int,int> pos){
  int y=pos.first,x=pos.second;
  int ny=y,nx=x;
  switch(arr[y][x]){
    case 'D': ny+=1;
              break;
    case 'U': ny-=1;
              break;
    case 'L': nx-=1;
              break;
    case 'R': nx+=1;
              break;
  }
  if(!inrange(ny,nx)) return;
  ind[y][x]++;
  v[m*ny+nx].push_back(m*y+x);
  return;
}

int dfs_count_vertex(pair<int,int> pos){
  int y=pos.first,x=pos.second,ret=1;
  check[y][x] = true;
  if(v[m*y+x].size()==0) return ret;
  for(auto &p:v[m*y+x]){
    int ny=p/m,nx=p%m;
    if(!check[ny][nx]){
      check[ny][nx]=true;
      ret+=dfs_count_vertex({ny,nx});
    }
  }
  return ret;

}


int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int ans=0;
  memset(check,false,sizeof(check));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      make_graph({i,j});
    }
  }
  memset(check,false,sizeof(check));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!ind[i][j]) ans+=dfs_count_vertex({i,j});
    }
  }

  cout<<ans<<'\n';

  return 0;
}
