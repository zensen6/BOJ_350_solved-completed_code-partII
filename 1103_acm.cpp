#include<bits/stdc++.h>
using namespace std;

int n,m;
bool check[51][51], check1[3000];
int dy[4] = {-1,0,0,1};
int dx[4] = {0,-1,1,0};
vector<int> node[3000];
char arr[51][51];
string x;
int ans = 0;
int d[3000];
int ind[3000];
int finished[3000];
bool cycle=false;


bool inrange(int y, int x){
  return x>=0&&x<m&&y>=0&&y<n;
}

int pos_to_num(int i, int j){
  return i*(m) + j;
}

bool isCycle(int here){
  if(finished[here] == 1) return false;
  if(finished[here] == -1) return true;
  finished[here] = -1;
  for(auto &p: node[here]){
    if(isCycle(p)){
      return true;
    }
  }
  finished[here] = 1;
  return false;
}



int main(){

  cin>>n>>m;
  getchar();
  for(int i=0;i<n;i++){
    cin>>x;
    for(int j=0;j<m;j++){
      arr[i][j] = x[j];
    }
  }

  for(int y=0;y<n;y++){
    for(int x=0;x<m;x++){
      for(int dir=0;dir<4;dir++){
        if(arr[y][x] != 'H'){
          int ny = y + dy[dir]*int(arr[y][x]-'0'), nx = x + dx[dir]*int(arr[y][x]-'0');
          if(inrange(ny,nx)){
            if(arr[ny][nx] != 'H'){
              node[pos_to_num(y,x)].push_back(pos_to_num(ny,nx));
            }
          }
        }
      }
    }
  }

  if(isCycle(0)){
    cout<<-1<<'\n';
    return 0;
  }

  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int f = q.front();
    q.pop();
    for(auto &p:node[f]){
      if(d[f] + 1 > d[p]){
        d[p] = d[f] + 1;
        q.push(p);
      }
    }
  }
  for(int i=0;i<3000;i++) ans = max(ans,d[i]);
  cout<<ans+1<<'\n';


  return 0;
}
