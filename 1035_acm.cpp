#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

char arr[5][5];
bool check[5][5];
vector<pair<int,int>> pos;
vector<int> per;
int ans = MAX, m[5][5], dy[4] = {0,-1,0,1}, dx[4] = {-1,0,1,0}, s;

bool inrange(int ny, int nx){
  return ny>=0&&ny<5&&nx>=0&&nx<5;
}

bool bfs(int mask){
  memset(check, false, sizeof(check));
  int c = 1;
  pair<int,int> first_pos;
  for(int i = 0; i < 25; i++){
    m[4-i/5][4-i%5] = ((1<<i)&mask ? 1:0);
    if(m[4-i/5][4-i%5] == 1){
      first_pos = {4-i/5,4-i%5};
    }
  }
  queue<pair<int,int>> q;
  q.push(first_pos);
  check[first_pos.first][first_pos.second] = true;
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    int y = p.first, x = p.second;
    for(int dir = 0; dir < 4; dir++){
      int ny = y + dy[dir], nx = x + dx[dir];
      if(inrange(ny,nx)){
        if(m[ny][nx] && !check[ny][nx]){
          check[ny][nx] = true;
          c++;
          q.push({ny,nx});
        }
      }
    }
  }
  return c==s;
}

int dist(pair<int,int> a, pair<int,int> b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void per_dist(int mask){
  vector<pair<int,int>> mask_pos;
  for(int i = 0 ; i < 25; i++){
    if((mask&(1<<i) ? 1:0)) mask_pos.push_back({4-i/5,4-i%5});
  }
  sort(per.begin(),per.end());
  do{
    int k = 0;
    for(int i = 0 ; i < s; i++){
      k += dist(pos[per[i]],mask_pos[i]);
    }
    ans = min(ans, k);
  }while(next_permutation(per.begin(),per.end()));
  return;
}

void proc(int index, int s, int mask){
  if(s == 0){
    if(bfs(mask)){
      per_dist(mask);
    }
  }else if(index == 25){
    return;
  }
  proc(index+1, s-1, mask|(1<<index));
  proc(index+1, s, mask);
  return;
}

int main(){

  for(int i = 0; i < 5; i++){
    for(int j = 0 ;j < 5; j++){
      scanf("%c",&arr[i][j]);
      if(arr[i][j] == '*'){
        pos.push_back({i,j});
      }
    }
    getchar();
  }
  s = pos.size();
  for(int i = 0; i < s; i++) per.push_back(i);
  proc(0,s,0);
  /*
  int mask = 0;
  //mask |= (1<<7);
  mask |= (1<<12);
  mask |= (1<<16);
  mask |= (1<<17);
  mask |= (1<<18);

  printf("%d",bfs(mask));
  */

  printf("%d\n",ans);
  return 0;
}
