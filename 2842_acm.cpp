#include<bits/stdc++.h>
using namespace std;

int n,arr[51][51],mini=1000001,maxi=0,x,y,dy[8] = {-1,0,0,1,-1,-1,1,1}, dx[8] = {0,-1,1,0,-1,1,-1,1};
char m[51][51];
bool check[51][51];
vector<pair<int,int>> pos;

bool inrange(int ny, int nx){
  return ny >=0 && ny < n && nx >= 0 && nx < n;
}

bool proc(int lowerbound, int upperbound){
  if(arr[y][x] < lowerbound || arr[y][x] > upperbound) return false;
  memset(check,false,sizeof(check));
  queue<pair<int,int>> q;
  q.push({y,x});
  check[y][x] = true;
  while(!q.empty()){
    auto f = q.front();
    q.pop();
    int iy = f.first, ix = f.second;
    for(int dir = 0; dir < 8; dir++){
      int ny = iy + dy[dir], nx = ix + dx[dir];
      if(inrange(ny,nx)){
        if(!check[ny][nx] && arr[ny][nx] >= lowerbound && arr[ny][nx] <= upperbound){
          check[ny][nx] = true;
          q.push({ny,nx});
        }
      }
    }
  }
  bool done = true;
  for(auto a: pos){
    if(!check[a.first][a.second]){
      done = false;
      break;
    }
  }
  return done;
}

int main(){

  scanf("%d",&n);
  getchar();
  for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j < n; j++){
      scanf("%1c",&m[i][j]);
    }
    getchar();
  }
  vector<int> fatigue;
  for(int i= 0 ; i < n; i++){
    for(int j = 0 ; j < n; j++){
      scanf("%d", &arr[i][j]);
      fatigue.push_back(arr[i][j]);
      if(m[i][j] == 'P'){
        y = i, x = j;
      }else if(m[i][j] == 'K'){
        pos.push_back({i,j});
      }
    }
  }
  sort(fatigue.begin(),fatigue.end());
  fatigue.erase(unique(fatigue.begin(),fatigue.end()),fatigue.end());
  int lo = 0, hi = 0, ans = 1000001;
  while(hi < fatigue.size()){
    if(proc(fatigue[lo], fatigue[hi])){
      ans = min(ans,fatigue[hi]-fatigue[lo]);
      //printf("%d %d\n",fatigue[hi],fatigue[lo]);
      lo++;
    }else{
      hi++;
    }
  }
  printf("%d\n",ans);

  return 0;
}
