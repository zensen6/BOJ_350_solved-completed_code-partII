#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int dy[4] = {-1,0,0,1};
int dx[4] = {0,-1,1,0};
int arr[11][11];
bool check[11][11];
int n,m,t;
pair<int,int> pos, gold, key;

bool inrange(int y, int x){
  return y>=0&&y<m&&x>=0&&x<n;
}

bool bfs(bool start){
  memset(check, false,sizeof(check));
  queue<pair<int,int>> q;
  if(start) q.push(pos);
  else q.push(key);
  check[pos.first][pos.second] = true;
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    int y = p.first, x = p.second;
    if(start){
      if(y == key.first && x == key.second) return true;
    }else{
      if(y == gold.first && x == gold.second) return true;
    }
    for(int i = 0 ; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(inrange(ny,nx)){
        if(!check[ny][nx] && arr[ny][nx] != 1){
          check[ny][nx] = true;
          q.push({ny,nx});
        }
      }
    }
  }
  return false;

}

int main(){
  cin>>t;
  while(t--){
    cin>>m>>n;
    for(int i = 0 ; i < m; i++){
      for(int j = 0 ; j < n; j++){
        cin>>arr[i][j];
        if(arr[i][j] == 2) gold = {i,j};
        else if(arr[i][j] == 3) pos = {i,j};
        else if(arr[i][j] == 4) key = {i,j};
      }
    }
    if(bfs(1)){
      if(bfs(0)){
        cout<<1<<'\n';
      }else{
        cout<<0<<'\n';
      }
    }else{
      cout<<0<<'\n';
    }
  }

  return 0;
}
