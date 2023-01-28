#include<bits/stdc++.h>
using namespace std;

int arr[5][5], dy[4] = {-1,0,0,1}, dx[4] = {0,-1,1,0};

map<int,int> m;

bool inrange(int y, int x){
  return y>=0&&y<5&&x>=0&&x<5;
}

void proc(int index, int y, int x, string s){
  if(index == 5){
    m[stoi(s)]++;
    return;
  }
  for(int dir = 0; dir < 4; dir++){
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(inrange(ny,nx)){
      string k = s;
      k += to_string(arr[ny][nx]);
      proc(index + 1, ny, nx,k);
    }
  }
}


int main(){

  for(int i = 0 ; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin>>arr[i][j];
    }
  }
  for(int i = 0 ; i < 5; i++){
    for(int j = 0; j < 5; j++){
      proc(0,i,j,to_string(arr[i][j]));
    }
  }
  //for(auto p : m) cout<<p.first<<'\n';

  cout<<m.size()<<'\n';
  return 0;
}
