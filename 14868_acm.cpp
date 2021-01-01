#include<bits/stdc++.h>
using namespace std;

int n,k,a,b,c=0,ans=0,group=1;
int m[2001][2001];
int check[2001][2001];
vector<pair<int,int>> pos;
queue<pair<pair<int,int>,pair<int,int>>> q;

int parent[4000001];
int find(int x){
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void Union(int y, int x){
  int y1 = find(y), x1 = find(x);
  if(y1 < x1){
    parent[x1] = y1;
    find(x);
  }else{
    parent[y1] = x1;
    find(y);
  }
  return;
}


bool inrange(int y, int x){
  return y>=1&&y<=n&&x>=1&&x<=n;
}

int dy[4] = {-1,0,0,1}, dx[4] = {0,-1,1,0};

void init(int i, int j){

  queue<pair<int,int>> q_init;
  q_init.push({i,j});
  check[i][j] = group;
  while(!q_init.empty()){
    auto t = q_init.front();
    q_init.pop();
    int y = t.first, x = t.second;
    for(int dir = 0; dir < 4; dir++){
      int ny = y + dy[dir], nx = x + dx[dir];
      if(inrange(ny,nx) && m[ny][nx]==0 && check[ny][nx]==-1){
        check[ny][nx] = group;
        q_init.push({ny,nx});
      }
    }
  }
  return;
}

void bfs(){

  for(auto p: pos){
    q.push({{p.first,p.second},{0,(n)*(p.first-1)+p.second}});
  }
  while(!q.empty()){
    auto t = q.front();
    q.pop();
    int y = t.first.first, x = t.first.second, here = t.second.first, from = t.second.second;
    for(int dir = 0; dir < 4; dir++){
      int ny = y + dy[dir], nx = x + dx[dir];
      if(inrange(ny,nx)){
        if(m[ny][nx] == -1){

          m[ny][nx] = here+1;
          check[ny][nx] = check[y][x];
          q.push({{ny,nx},{here+1,check[y][x]}});
        }else{
          if(parent[check[ny][nx]] != parent[check[y][x]]){
            Union(check[ny][nx], check[y][x]);
            find(check[ny][nx]);
            find(check[y][x]);
            c++;
            ans = max(m[ny][nx],here);
            //cout<<c<<" "<<ans<<'\n';
            if(c == group-2){
              cout<<ans<<'\n';
              return;
            }

          }

        }

      }
    }

  }
  return;

}


int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>k;

  memset(m,-1,sizeof(m));
  memset(check,-1,sizeof(check));
  memset(parent,-1,sizeof(parent));
  //for(int i = 1; i<= n*n; i++) parent[i] = i;
  for(int i = 0 ; i < k; i++){
    cin>>a>>b;
    m[b][a] = 0;
    pos.push_back({b,a});
  }

  if(k==1){
    cout<<0<<'\n';
    return 0;
  }
  for(int i=1; i<=n;i++){
    for(int j=1;j<=n;j++){
      if(!m[i][j] && check[i][j]==-1){
        init(i,j);
        ++group;
      }
    }
  }
  for(int i = 1; i < group; i++) parent[i]=i;
  /*
  for(int i=1; i<=n;i++){
    for(int j=1;j<=n;j++){
      if(check[i][j]>0){
        parent[n*(i-1)+j] = check[i][j];
      }
    }
  }
  */
  /*
  for(int i = n; i>= 1; i--){
    for(int j = 1; j<=n ;j++){
      cout<<parent[n*(i-1)+j]<<" ";
    }
    cout<<'\n';
  }*/

  //cout<<group<<'\n';
  if(group-2==0){
    cout<<0<<'\n';
    return 0;
  }

  /*
  for(int i = n; i>= 1; i--){
    for(int j = 1; j<=n ;j++){
      cout<<check[i][j]<<" ";
    }
    cout<<'\n';
  }
  */
  bfs();


  return 0;
}
