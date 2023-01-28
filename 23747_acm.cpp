#include<bits/stdc++.h>
using namespace std;

int r,c,sr,sc;
string arr[1001];
string ans[1001];
string query;

int dy[4] = {-1,0,0,1};
int dx[4] = {0,-1,1,0};
bool check[1001][1001];
bool inrange(int y, int x){
  return y<=r-1&&y>=0&&x<=c-1&&x>=0;
}


void bfs(int y, int x){
  char T = arr[y][x];
  queue<pair<int,int>> q;
  q.push({y,x});
  check[y][x] = true;
  ans[y][x] = '.';
  while(!q.empty()){
    auto f = q.front();
    y = f.first, x = f.second;
    q.pop();
    for(int dir = 0;dir < 4; dir++){
      int ny = y + dy[dir], nx = x + dx[dir];
      if(inrange(ny,nx)){
        if(!check[ny][nx] && arr[ny][nx] == T){
          check[ny][nx] = true;
          ans[ny][nx] = '.';
          q.push({ny,nx});
        }
      }
    }
  }
  return;
}

void finally(int y, int x){
  ans[y][x] = '.';
  for(int dir=0;dir<4;dir++){
    int ny = y + dy[dir], nx = x + dx[dir];
    if(inrange(ny,nx)){
      ans[ny][nx] = '.';
    }
  }
  return;
}

int main(){

  cin>>r>>c;
  for(int i=0;i<r;i++){
    cin>>arr[i];
  }
  cin>>sr>>sc;
  cin>>query;
  for(int i=0;i<r;i++){
    ans[i] = "#";
    for(int j=1;j<c;j++) ans[i] += "#";
  }

  int ny = sr-1, nx = sc-1;
  for(auto &p: query){
    if(p=='W'){
      bfs(ny, nx);
    }else if(p=='L'){
      nx--;
    }else if(p=='R'){
      nx++;
    }else if(p=='U'){
      ny--;
    }else{
      ny++;
    }
  }
  finally(ny,nx);
  for(int i=0;i<r;i++){
    cout<<ans[i]<<'\n';
  }


  return 0;
}
