#include<bits/stdc++.h>
using namespace std;

int arr[16][16], n, d[16][10][1<<16];

int proc(int here, int cost, int mask){
  int& ret = d[here][cost][mask];
  if(ret != -1) return ret;
  ret = 0;
  for(int i = 1; i <= n; i++){
    if(((1<<i)&mask) == 0 && arr[here][i] >= cost){
      ret = max(ret,1+proc(i,arr[here][i],mask|(1<<i)));
    }
  }
  return ret;
}

int main(){

  memset(arr,0,sizeof(arr));
  memset(d,-1,sizeof(d));
  scanf("%d",&n);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      scanf("%1d",&arr[i][j]);
    }
  }

  printf("%d\n",proc(1,0,1<<1)+1);

  return 0;
}
