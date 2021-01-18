#include<bits/stdc++.h>
using namespace std;

int domino[7] = {7,7,7,7,7,7,7};
int n,m,x,y;
long long ans = 0;
vector<int> edge[8];
int check[8];
bool connected[8][8];


int count(){
  int c=0;
  for(int i = 0 ; i < 8; i++){
    for(int j = i+1; j < 8; j++){
      if(connected[i][j]==1) c++;
    }
  }
  return m-c;

}

void dfs(int here){

  ans = max<long long>(ans,count());
  for(auto p: edge[here]){
    if(check[p]==-1){
      if(domino[check[here]] == 0){
        return;
      }
      for(int i = 1; i <= 6; i++){
        if(domino[i] > 0){
          check[p] = i;
          domino[check[here]]--;
          domino[i]--;
          connected[here][p] = 0;
          connected[p][here] = 0;
          dfs(p);
          connected[p][here] = 1;
          connected[here][p] = 1;
          domino[i]++;
          domino[check[here]]++;
        }
      }
    }
    else if(connected[here][p]){
      if(domino[check[here]] > 0 && domino[check[p]] > 0){
        domino[check[here]]--;
        domino[check[p]]--;
        connected[here][p] = 0;
        connected[p][here] = 0;
        dfs(p);
        connected[here][p] = 1;
        connected[p][here] = 1;
        domino[check[here]]++;
        domino[check[p]]++;
      }
    }
  }
  return;
}

int main(){

  int start = 10;
  memset(check, -1, sizeof(check));
  memset(connected,0,sizeof(connected));
  cin>>n>>m;
  for(int i = 0 ; i < m; i++){
    cin>>x>>y;
    edge[x].push_back(y);
    edge[y].push_back(x);
    start = min(x,start);
    connected[x][y] = 1;
    connected[y][x] = 1;
  }
  for(int i = 1; i <= 6; i++){
    check[start]=i;
    dfs(start);
  }
  cout<<ans<<'\n';

  return 0;
}
