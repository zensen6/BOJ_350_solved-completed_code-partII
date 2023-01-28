#include<bits/stdc++.h>
using namespace std;

int r,c,arr[501][501],num[501][501],dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
int format_to_num(int y, int x){
  return y*c+x;
}
pair<int,int> format_to_pos(int k){
  return {k/c,k%c};
}

bool inrange(int y, int x){
  return y>=0&&y<r&&x>=0&&x<c;
}

int p[250001];

int Find(int x){
  if(x==p[x]) return x;
  return p[x] = Find(p[x]);
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for(int i=0;i<250001;i++) p[i]=i;

  cin>>r>>c;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin>>arr[i][j];
    }
  }
  for(int y=0;y<r;y++){
    for(int x=0;x<c;x++){
      bool can=false;
      int minimum = arr[y][x],posy,posx;
      for(int dir=0;dir<8;dir++){
        int ny=y+dy[dir], nx=x+dx[dir];
        if(inrange(ny,nx)){
          if(arr[ny][nx]<minimum){
            can=true;
            minimum=min(minimum,arr[ny][nx]);
            posy=ny,posx=nx;
          }
        }
      }
      if(can){
        p[format_to_num(y,x)] = format_to_num(posy,posx);
      }
    }
  }

  for(int y=0;y<r;y++){
    for(int x=0;x<c;x++){
      auto k =format_to_pos(Find(format_to_num(y,x)));
      num[k.first][k.second]++;
    }
  }

  for(int y=0;y<r;y++){
    for(int x=0;x<c;x++){
      cout<<num[y][x]<<" ";
    }
    cout<<'\n';
  }


  return 0;
}
