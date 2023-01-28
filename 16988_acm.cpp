#include<bits/stdc++.h>
using namespace std;

int dy[4]={0,-1,0,1},dx[4]={-1,0,1,0},n,m,arr[21][21];
vector<pair<int,int>> v;
bool check[21][21],checkOne[21][21];
bool inrange(int y, int x){
  return y>=0&&y<n&&x>=0&&x<m;
}

void init(int y, int x){
  queue<pair<int,int>> q;
  vector<pair<int,int>> pos;
  q.push({y,x});
  check[y][x] = true;
  while(!q.empty()){
    auto t = q.front();
    q.pop();
    for(int dir=0;dir<4;dir++){
      int ny=t.first+dy[dir],nx=t.second+dx[dir];
      if(inrange(ny,nx)){
        if(!check[ny][nx]){
          if(!arr[ny][nx]&&!checkOne[ny][nx]){
            checkOne[ny][nx]=true;
            pos.push_back({ny,nx});
          }
          if(arr[ny][nx]==2){
            check[ny][nx]=true;
            q.push({ny,nx});
          }
        }
      }
    }
  }
    for(auto &p:pos){
      v.push_back(p);
    }

  return;
}

int score(int y,int x){
  int c = 1;
  queue<pair<int,int>> q;
  q.push({y,x});
  check[y][x] = true;
  bool unable=false;
  while(!q.empty()){
    auto t = q.front();
    q.pop();
    for(int dir=0;dir<4;dir++){
      int ny=t.first+dy[dir],nx=t.second+dx[dir];
      if(inrange(ny,nx)){
        if(!check[ny][nx]){
          if(!arr[ny][nx]){
            unable=true;
          }
          if(arr[ny][nx]==2){
            c++;
            check[ny][nx]=true;
            q.push({ny,nx});
          }
        }
      }
    }
  }
  c=(unable==false?c:0);
  return c;
}

int main(){

  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==2&&!check[i][j]){
        init(i,j);
      }
    }
  }

//
  //for(auto &p:v)cout<<p.first<<" "<<p.second<<"\n";
//

  int len=v.size();
  int ans=0;
  if(len==1){
    memset(check,false,sizeof(check));
    arr[v[0].first][v[0].second]=1;
    int t_score=0;
    for(int y=0;y<n;y++){
      for(int x=0;x<m;x++){
        if(arr[y][x]==2 && !check[y][x]){
          int s=score(y,x);
          t_score+=s;
        }
      }
    }
    arr[v[0].first][v[0].second]=0;
    ans=max(ans,t_score);
  }
  else{
    for(int i=0;i<len-1;i++){
      for(int j=i+1;j<len;j++){
        memset(check,false,sizeof(check));
        arr[v[i].first][v[i].second]=1;
        arr[v[j].first][v[j].second]=1;
        int t_score=0;
        for(int y=0;y<n;y++){
          for(int x=0;x<m;x++){
            if(arr[y][x]==2 && !check[y][x]){
              int s=score(y,x);
              t_score+=s;
            }
          }
        }
        arr[v[i].first][v[i].second]=0;
        arr[v[j].first][v[j].second]=0;
        ans=max(ans,t_score);
      }
    }
  }
  cout<<ans<<"\n";

  return 0;
}
