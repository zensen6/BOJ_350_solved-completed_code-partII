#include<bits/stdc++.h>
using namespace std;

int r,c,dy[4] = {-1,0,0,1}, dx[4] = {0,-1,1,0}, id=0, count=0;
char arr[1501][1501];
int group[2500000];
int check[1501][1501];
vector<pair<int,int>> initial;
set<int> s;

bool inrange(int y, int x){
  return y>=0&&y<r&&x>=0&&x<c;
}

void init(){
  memset(check, 0, sizeof(check));
  return;
}

void func(int y, int x){
  ++id;
  queue<pair<int,int>> q;
  q.push({y,x});
  while(!q.empty()){
    auto t = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir++){
      int ny = t.first+dy[dir], nx = t.second+dx[dir];
      if(inrange(ny,nx)){
        if(!check[ny][nx] && (arr[ny][nx] == 'L'||arr[ny][nx] == '.')){
          check[ny][nx] = 1;
          q.push({ny,nx});
          if(arr[ny][nx] == 'L'){
            s.insert(id);
          }
          group[c*(ny-1)+nx] = id;
        }
      }
    }
  }
  return;

}

int proc(){
  init();
  for(int i = 0  ; i < r; i++){
    for(int j = 0 ; j < c; j++){
      if(!check[i][j] && (arr[i][j] == '.' || arr[i][j] == 'L')){
        func(i,j);
      }
      if(arr[i][j] == '.'){
        for(int dir = 0; dir < 4; dir++){
          int ny = i + dy[dir], nx = j + dx[dir];
          if(inrange(ny,nx)){
            if(arr[ny][nx] == 'X') initial.push_back({ny,nx});
          }
        }
      }
    }
  }
  init();
  queue<pair<pair<int,int>,int>> q;
  for(auto p:initial){
    q.push({{p.first, p.second},0});
  }
  while(!q.empty()){
    auto t = q.front();
    q.pop();
    int y = t.first.first, x = t.first.second, here= t.second;
    for(int dir = 0; dir < 4; dir++){
      int ny = y+dy[dir], nx = x+dx[dir];
      if(inrange(ny,nx)){
        if(!check[ny][nx] && arr[ny][nx] == 'X'){
          arr[ny][nx] = '.';
          check[ny][nx] =here+1;
          q.push({{ny,nx},here+1});
        }else if((arr[ny][nx] == 'L' || arr[ny][nx] == '.')&&group[c*(ny-1)+nx] != group[c*(y-1)+x]){
          return max(here,check[ny][nx]);
        }
      }
    }

  }
  return 0;

}

int main(){

    scanf("%d %d",&r,&c);
    getchar();
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        scanf("%1c",&arr[i][j]);
      }
      getchar();
    }
    printf("%d\n",proc());


  return 0;
}
