#include<bits/stdc++.h>
#define MOD 1000007LL
using namespace std;

typedef long long ll;

int n,m,c,x,y,arr[52][52];
vector<int> can_reach[52];
pair<int,int> pos[52];
ll d[52][52], t[52][52], skip[52][52][52];

void path(int cur){

  y=pos[cur].first, x=pos[cur].second;
  for(auto &next:can_reach[cur]){
    memset(t,0,sizeof(t));
    int ny=pos[next].first, nx=pos[next].second;
    for(int i=y;i<=ny;i++){
      for(int j=x;j<=nx;j++){
        if(arr[i][j]==cur) t[i][j]=1LL;
        else if(arr[i][j]!=-1 && arr[i][j]!=next) continue;
        else{
          t[i][j] += (t[i-1][j] + t[i][j-1]);
          t[i][j] %= MOD;
        }
      }
    }
    d[cur][next] = t[ny][nx];
  }
  return;
}

int main(){

  cin>>n>>m>>c;
  memset(arr,-1,sizeof(arr));
  pos[0] = {1,1};
  pos[c+1] = {n,m};
  for(int i=1;i<=c;i++){
    cin>>y>>x;
    arr[y][x] = i;
    pos[i] = {y,x};
  }
  arr[n][m] = (arr[n][m] == -1? c+1:arr[n][m]);
  arr[1][1] = (arr[1][1] == -1? 0:arr[1][1]);
  for(int row=1;row<=n;row++){
    for(int col=1;col<=m;col++){
      if(arr[row][col] > -1){
        for(int i=row;i<=n;i++){
          for(int j=col;j<=m;j++){
            if((i!=row||j!=col)&&(arr[i][j]>arr[row][col])){
              can_reach[arr[row][col]].push_back(arr[i][j]);
            }
          }
        }
      }
    }
  }

  for(int i=0;i<=c;i++) path(i);
  for(int prev=0;prev<=c;prev++){
    for(int next=prev+1;next<=c+1;next++){
       skip[0][prev][next] += d[prev][next];
    }
  }

  for(int k=1;k<=c;k++){
    for(int i=0;i<=c;i++){
      for(int j=i+1;j<=c+1;j++){
        for(int mid=i+1;mid<j;mid++){
          skip[k][i][j] += skip[k-1][i][mid] * d[mid][j];
          skip[k][i][j] %= MOD;
        }
      }
    }
  }
  if(n==1&&m==1){
    if(c==0) cout<<1<<'\n';
    else cout<<0<<" "<<1<<'\n';
    return 0;
  }

  if(arr[1][1] > 0){
    if(arr[n][m] <= c && arr[n][m] > 0){
      for(int k=0;k<=min(1,c);k++) cout<<0<<" ";
      for(int k=2;k<=c;k++) cout<<skip[k-2][arr[1][1]][arr[n][m]]<<" ";
    }else{
      cout<<0<<" ";
      for(int k=1;k<=c;k++) cout<<skip[k-1][arr[1][1]][arr[n][m]]<<" ";
    }
  }else{
    if(arr[n][m] <= c && arr[n][m] > 0){
      cout<<0<<" ";
      for(int k=1;k<=c;k++) cout<<skip[k-1][arr[1][1]][arr[n][m]]<<" ";
    }else{
      for(int k=0;k<=c;k++) cout<<skip[k][arr[1][1]][arr[n][m]]<<" ";
    }
  }
  return 0;
}
