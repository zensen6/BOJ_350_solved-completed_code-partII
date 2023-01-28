#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int n,m, dy[4]={0,-1,0,1},dx[4]={-1,0,1,0},should_check,turn_ans=MAX;
char arr[32][32];
bool check[32][32];

bool inrange(int y, int x){
  return y>=1&&y<=n&&x>=1&&x<=m;
}

void proc(int c,int direction,int turn,int y,int x){//direction = prev state direction
    if(c==should_check){
      turn_ans=min(turn_ans,turn);
      return;
    }
    int sy=y,sx=x,alpha=0;
    check[sy][sx]=true;
    for(int i=1;i<=3;i+=2){
        alpha=0;
        int dir=(direction+i)%4;
        int ny=y+dy[dir],nx=x+dx[dir];
        bool trial=false;
        if(!inrange(ny,nx) || arr[ny][nx] =='*' || check[ny][nx]) continue;
        while(!check[ny][nx] && arr[ny][nx]!='*'){
          trial=true;
          alpha++;
          check[ny][nx] = true;
          ny+=dy[dir];
          nx+=dx[dir];
          if(!inrange(ny,nx)) break;
        }
        ny-=dy[dir];
        nx-=dx[dir];
        if(trial) proc(c+alpha,dir,turn+1,ny,nx);
        while(ny!=sy&&nx!=sx){
          alpha--;
          check[ny][nx] = false;
          ny-=dy[dir];
          nx-=dx[dir];
        }
    }
    return;
}

int main(){

  int tc=1;
  while(scanf("%d %d",&n,&m)){
    turn_ans=MAX;
    getchar();
    should_check=n*m;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        scanf("%1c",&arr[i][j]);
        if(arr[i][j]=='*'){
          should_check--;
        }
      }
      getchar();
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(arr[i][j]=='.'){
          for(int dir=0;dir<=1;dir++){
            memset(check,false,sizeof(check));
            proc(1,dir,0,i,j);
          }
        }
      }
    }

    turn_ans = (should_check==1?1:(turn_ans==MAX?-1:turn_ans));
    printf("Case %d: %d\n",tc++,turn_ans);

  }



  return 0;
}
