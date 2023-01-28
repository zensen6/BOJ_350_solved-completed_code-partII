#include<cstdio>
#include<memory.h>

int n,m;
char x;
int arr[751][751], l[751][751], r[751][751], a[751][751];

auto max = [](int x, int y){ return x < y? y : x;};
auto min = [](int x, int y){ return x < y? x : y;};

int main(){

  memset(arr,0,sizeof(arr));
  memset(l,0,sizeof(l));
  memset(r,0,sizeof(r));
  memset(a,0,sizeof(a));

  scanf("%d %d",&n,&m);
  getchar();
  for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j < m; j++){
      scanf("%1c",&x);
      arr[i][j] = (int)(x-'0');
      if(arr[i][j] == 1){
        l[i][j] = 1;
        r[i][j] = 1;
        a[i][j] = 1;
      }
    }
    getchar();
  }

  int mid = (min(n,m)-1)/2;
  for(int k = 1; k <= mid; k++){
    for(int i = 0+k; i < n-k; i++){
      for(int j = 0+k; j < m-k; j++){
        if(l[i][j-1] == k && arr[i+k][j] && arr[i-k][j]) l[i][j] = max(l[i][j],l[i][j-1] + 1);
        if(r[i][j+1] == k && arr[i+k][j] && arr[i-k][j]) r[i][j] = max(r[i][j],r[i][j+1] + 1);
        if(l[i][j] == r[i][j]) a[i][j] = max(a[i][j],l[i][j]);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      ans = max(ans,a[i][j]);
    }
  }
  printf("%d\n",ans);
  return 0;
}
