#include<bits/stdc++.h>
using namespace std;

int n,m;
char arr[26][26];
int c[26][26], dy[5] = {0,1,0,-1,0}, dx[5] = {0,0,1,0,-1};
pair<pair<int,int>,pair<int,int>> block[5] = {{{0,0},{0,0}}, {{0,1},{1,0}}, {{-1,0},{0,1}}, {{0,-1},{-1,0}}, {{-1,0},{1,0}}};

bool inrange(int y, int x){
  return y>=0&&y<n&&x>=0&&x<m;
}
bool Misconnected = false, Zisconnected = false;

void res(pair<int,int> Mpos, bool isM){
  int mi = Mpos.first, mj = Mpos.second;
  bool surround = false;
  for(int dir = 1; dir <= 4; dir++){
    int ny = mi+dy[dir], nx = mj+dx[dir];
    if(inrange(ny,nx)){
      if(arr[ny][nx] == (char)((dir+1==4?dir+1:(dir+1)%4)+'0') || arr[ny][nx] == (char)((dir+2==4?dir+2:(dir+2)%4)+'0')){
        surround = true;
        if(isM) Misconnected = true;
        else Zisconnected = true;
      }else if(((dir&1)&&arr[ny][nx]=='|') || (arr[ny][nx]=='+') || (!(dir&1)&&arr[ny][nx]=='-')){
        surround = true;
        if(isM) Misconnected = true;
        else Zisconnected = true;
      }
    }
  }
  if(surround){
    for(int dir = 1; dir <= 4; dir++){
      int ny = mi+dy[dir], nx = mj+dx[dir];
      if(inrange(ny,nx)){
        c[ny][nx]-=1;
      }
    }
  }
}

int main(){
  pair<int,int> Mpos, Zpos;
  memset(c,0,sizeof(c));
  scanf("%d %d",&n,&m);
  getchar();
  for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j< m; j++){
      scanf("%1c",&arr[i][j]);
      if(arr[i][j] == 'M') Mpos = {i,j};
      if(arr[i][j] == 'Z') Zpos = {i,j};
    }
    getchar();
  }

  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < m; j++){
      if(arr[i][j] == '|'){
        if(inrange(i+1,j)){
          c[i+1][j]++;
        }
        if(inrange(i-1,j)){
          c[i-1][j]++;
        }
      }else if(arr[i][j] == '-'){
        if(inrange(i,j-1)){
          c[i][j-1]++;
        }
        if(inrange(i,j+1)){
          c[i][j+1]++;
        }
      }else if(arr[i][j] == '+' || arr[i][j] == 'M' || arr[i][j] == 'Z'){
        for(int dir = 1; dir <= 4; dir++){
          if(inrange(i+dy[dir],j+dx[dir])){
            c[i+dy[dir]][j+dx[dir]]++;
          }
        }
      }else if(arr[i][j] >= '1' && arr[i][j] <= '4'){
        int num = (int)(arr[i][j] - '0');
        if(inrange(i+block[num].first.first, j+block[num].first.second)){
          c[i+block[num].first.first][j+block[num].first.second]++;
        }
        if(inrange(i+block[num].second.first, j+block[num].second.second)){
          c[i+block[num].second.first][j+block[num].second.second]++;
        }
      }
    }
  }

  res(Mpos,true);
  res(Zpos,false);

  //
  /*
  for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j < m; j++){
      printf("%d ",c[i][j]);
    }
    printf("\n");
  }
  */


  //
  //printf("M:%d Z:%d\n",Misconnected,Zisconnected);

  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < m; j++){
      if(c[i][j] >= 2 && arr[i][j] == '.'){
        int k = 0, Z = 0, M = 0;
        int check[5] = {0,0,0,0,0};
        for(int dir = 1; dir <= 4; dir++){
          int ny = i+dy[dir], nx = j+dx[dir];
          if(inrange(ny,nx)){
            if(arr[ny][nx] == 'M'){
              if(!Misconnected){
                M++;
                k++;
                check[dir]=1;
              }
            }
            else if(arr[ny][nx] == 'Z'){
              if(!Zisconnected){
                Z++;
                k++;
                check[dir]=1;
              }
            }
            else if(arr[ny][nx] == (char)((dir+1==4?dir+1:(dir+1)%4)+'0') || arr[ny][nx] == (char)((dir+2==4?dir+2:(dir+2)%4)+'0')){
              k++;
              check[dir]=1;
            }else if(((dir&1)&&arr[ny][nx]=='|') || (arr[ny][nx]=='+') || (!(dir&1)&&arr[ny][nx]=='-')){
              k++;
              check[dir]=1;
            }
          }
        }

        if(k==2){
          printf("%d %d ",i+1,j+1);
          if(check[1]){
            if(check[2]){
              printf("%d\n",1);
            }else if(check[3]){
              printf("%c\n",'|');
            }else if(check[4]){
              printf("%d\n",4);
            }
          }else if(check[2]){
            if(check[3]){
              printf("%d\n",2);
            }else if(check[4]){
              printf("%c\n",'-');
            }
          }else if(check[3]){
            printf("%d\n",3);
          }
          return 0;
        }
        else if(k==4){
          printf("%d %d %c\n",i+1,j+1,'+');
          return 0;
        }
      }
    }
  }





  return 0;
}
