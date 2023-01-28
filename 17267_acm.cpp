#include<bits/stdc++.h>
using namespace std;

bool check[1001][1001];
int arr[1001][1001];
int n,m, dy[2] = {0,0}, dx[2] = {-1,1}, l, r;

bool inrange(int y, int x){
  return y>=0&&y<n&&x>=0&&x<m;
}
int start_y,  start_x;
void bfs(){

  queue<pair<pair<int,int>,pair<int,int>>> q;
  check[start_y][start_x] = 1;
  q.push({{start_y,start_x},{l,r}});
  while(!q.empty()){
    auto k = q.front();
    q.pop();
    int y = k.first.first, x = k.first.second;
    int rl = k.second.first, rr = k.second.second;
    for(int dir = 0 ; dir < 2; dir++){
      int ny = y + dy[dir], nx = x + dx[dir];
      if(inrange(ny,nx)){
        if(!check[ny][nx] && arr[ny][nx] == 0){
          if(dir == 0 && rl > 0){
            check[ny][nx] = 1;
            q.push({{ny,nx},{rl-1,rr}});
          }else if(dir == 1 && rr > 0){
            check[ny][nx] = 1;
            q.push({{ny,nx},{rl,rr-1}});
          }
        }
      }
    }
    int sy = y, sx = x;
    while(sy-1>=0&&arr[sy-1][sx]==0&&!check[sy-1][sx]){
      check[sy-1][sx] = 1;
      q.push({{sy-1,sx},{rl,rr}});
      sy--;
    }
    sy = y;
    sx = x;
    while(sy+1<n&&arr[sy+1][sx]==0&&!check[sy+1][sx]){
      check[sy+1][sx] = 1;
      q.push({{sy+1,sx},{rl,rr}});
      sy++;
    }
  }

}

int main(){

  scanf("%d %d",&n,&m);
  scanf("%d %d",&l,&r);
  for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j < m; j++){
      scanf("%1d",&arr[i][j]);
      if(arr[i][j] == 2){
        start_y = i;
        start_x = j;
      }
    }
  }


  bfs();
  int c = 0;
  for(int i = 0; i<n; i++){
    for(int j= 0 ; j < m; j++){
      if(check[i][j])c++;
      //printf("%1d",check[i][j]);
    }
    //printf("\n");
  }
  printf("%d\n",c);

  return 0;
}
