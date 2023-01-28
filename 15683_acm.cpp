#include<bits/stdc++.h>
using namespace std;

int n,m,c=0,ans=1000000;
int arr[9][9];
int copy_[9][9];
int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
vector<pair<int,int>> pos;

bool inrange(int y, int x){
  return y>=0&&y<n&&x>=0&&x<m;
}

void memory(vector<int> dir, bool del){
  if(!del){
    for(int i = 0 ; i < n; i++){
      for(int j = 0; j < m; j++){
        for(int k = 0 ; k < pos.size(); k++){
          int y = pos[k].first, x = pos[k].second;
          int ny = y, nx = x;
          if(arr[y][x] == 1){
            while(inrange(ny,nx) && arr[ny][nx] != 6){
              copy_[ny][nx] = 7;
              ny += dy[dir[k]], nx += dx[dir[k]];
            }
          }else if(arr[y][x] == 2){
            int ny1 = ny, nx1 = nx, ny2 = ny, nx2 = nx;
            while(inrange(ny1,nx1) && arr[ny1][nx1] != 6){
              copy_[ny1][nx1] = 7;
              ny1 += dy[dir[k]], nx1 += dx[dir[k]];
            }
            while(inrange(ny2,nx2) && arr[ny2][nx2] != 6){
              copy_[ny2][nx2] = 7;
              ny2 += dy[(dir[k] + 2)%4], nx2 += dx[(dir[k] + 2)%4];
            }
          }else if(arr[y][x] == 3){
            int ny1 = ny, nx1 = nx, ny2 = ny, nx2 = nx;
            while(inrange(ny1,nx1) && arr[ny1][nx1] != 6){
              copy_[ny1][nx1] = 7;
              ny1 += dy[dir[k]], nx1 += dx[dir[k]];
            }
            while(inrange(ny2,nx2) && arr[ny2][nx2] != 6){
              copy_[ny2][nx2] = 7;
              ny2 += dy[(dir[k] + 1)%4], nx2 += dx[(dir[k] + 1)%4];
            }
          }else if(arr[y][x] == 4){
            int ny1 = ny, nx1 = nx, ny2 = ny, nx2 = nx, ny3 = ny, nx3 = nx;
            while(inrange(ny1,nx1) && arr[ny1][nx1] != 6){
              copy_[ny1][nx1] = 7;
              ny1 += dy[dir[k]], nx1 += dx[dir[k]];
            }
            while(inrange(ny2,nx2) && arr[ny2][nx2] != 6){
              copy_[ny2][nx2] = 7;
              ny2 += dy[(dir[k] + 1)%4], nx2 += dx[(dir[k] + 1)%4];
            }
            while(inrange(ny3,nx3) && arr[ny3][nx3] != 6){
              copy_[ny3][nx3] = 7;
              ny3 += dy[(dir[k] + 2)%4], nx3 += dx[(dir[k] + 2)%4];
            }
          }else if(arr[y][x] == 5){
            int ny1 = ny, nx1 = nx, ny2 = ny, nx2 = nx, ny3 = ny, nx3 = nx, ny4 = ny, nx4 = nx;
            while(inrange(ny1,nx1) && arr[ny1][nx1] != 6){
              copy_[ny1][nx1] = 7;
              ny1 += dy[dir[k]], nx1 += dx[dir[k]];
            }
            while(inrange(ny2,nx2) && arr[ny2][nx2] != 6){
              copy_[ny2][nx2] = 7;
              ny2 += dy[(dir[k] + 1)%4], nx2 += dx[(dir[k] + 1)%4];
            }
            while(inrange(ny3,nx3) && arr[ny3][nx3] != 6){
              copy_[ny3][nx3] = 7;
              ny3 += dy[(dir[k] + 2)%4], nx3 += dx[(dir[k] + 2)%4];
            }
            while(inrange(ny4,nx4) && arr[ny4][nx4] != 6){
              copy_[ny4][nx4] = 7;
              ny4 += dy[(dir[k] + 3)%4], nx4 += dx[(dir[k] + 3)%4];
            }
          }
        }
      }
    }
  }else{
    for(int i = 0 ; i < n;  i++){
      for(int j = 0 ; j < m; j++){
        copy_[i][j] = arr[i][j];
      }
    }
  }

}



int count_(){
  int ans_ = 0;
  for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j < m; j++){
      if(copy_[i][j] == 0) ans_++;
    }
  }
  return ans_;
}

void proc(int index, vector<int>  dir){
  if(index == c){
    memory(dir,false);
    ans = min(ans, count_());
    memory(dir,true);
    return;
  }
  dir.push_back(0);
  proc(index+1,dir);
  if(arr[pos[index].first][pos[index].second] == 2){
    dir.pop_back();
    dir.push_back(1);
    proc(index+1,dir);
  }else if(arr[pos[index].first][pos[index].second] <= 4){
    for(int i = 1; i < 4; i++){
      dir.pop_back();
      dir.push_back(i);
      proc(index+1,dir);
    }
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j < m; j++){
      cin>>arr[i][j];
      if(arr[i][j] >= 1 && arr[i][j] < 6) {
        pos.push_back({i,j});
        c++;
      }
    }
  }
  vector<int> dir;
  memory(dir,1);
  proc(0,dir);
  cout<<ans<<'\n';

  return 0;
}
