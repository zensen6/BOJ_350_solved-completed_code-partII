#include<bits/stdc++.h>
using namespace std;

int w,h;
char arr[102][102];
int check[102][102], dy[4] = {0,1,0,-1}, dx[4] = {-1,0,1,0};
vector<pair<int,int>> des;
queue<pair<pair<int,int>,int>> q;
bool inrange(int y, int x){
  return y>=0&&y<h&&x>=0&&x<w;
}
//U:0 R:1 D:2 L:3

void doing(int y, int x, int dir, int direction){

  for(int i = 1; i < 101; i++){
    int ny = y + dy[dir]*i, nx = x + dx[dir]*i;
    if(inrange(ny,nx)){
      if(check[ny][nx] == -1 && arr[ny][nx] != '*'){
        check[ny][nx] = check[y][x] + (direction == dir ? 0 : 1);
        q.push({{ny,nx},dir});
      }else if(check[ny][nx] != -1 && arr[ny][nx] != '*'){
        continue;
      }else{
        break;
      }
    }else{
      break;
    }
  }
  return;
}

int proc(){

  check[des[0].first][des[0].second] = 0;
  for(int dir = 0; dir < 4; dir++){
    for(int i = 1 ; i < 101; i++){
      int ny = des[0].first + dy[dir]*i;
      int nx = des[0].second + dx[dir]*i;
      if(inrange(ny,nx)){
        if(arr[ny][nx] != '*'){
          check[ny][nx] = 0;
          q.push({{ny,nx},dir});
        }else{
          break;
        }
      }else{
        break;
      }
    }
  }
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    int y = p.first.first, x = p.first.second, direction = p.second;
    for(int dir = 0; dir < 4; dir++){
      doing(y,x,dir,direction);
    }
  }
  return check[des[1].first][des[1].second];
}


int main(){
  memset(check,-1,sizeof(check));
  scanf("%d %d",&w,&h);
  getchar();
  for(int i = 0 ; i < h; i++){
    for(int j = 0 ; j < w; j++){
      scanf("%1c", &arr[i][j]);
      if(arr[i][j] == 'C'){
        des.push_back({i,j});
      }
    }
    getchar();
  }
  /*
  for(int i = 0 ; i < h; i++){
    for(int j = 0 ; j < w; j++){
      printf("%1c",arr[i][j]);
    }
    printf("\n");
  }
  */
  printf("%d\n",proc());

  //printf("%d %d\n",des[0].first, des[0].second);
  /*
  for(int i = 0 ; i < h; i++){
    for(int j = 0 ; j < w; j++){
      printf("%d ",check[i][j]);
    }
    printf("\n");
  }
*/
  return 0;
}
