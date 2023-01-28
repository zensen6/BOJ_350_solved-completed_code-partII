#include<bits/stdc++.h>
using namespace std;

int arr[2001][2001], tc, n;
char bp;

int main(){

  cin>>tc;
  while(tc--){
    int one=0;
    getchar();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        scanf("%1d",&arr[i][j]);
        if(arr[i][j]) one++;
      }
    }
    int overlap=0;
    for(int s=0;s<n;s++){
      int c=0;
      for(int p=0;p<n;p++){
        if(arr[p%n][(s+p)%n]) c++;
      }
      overlap=max(overlap,c);
    }
    printf("%d\n",n-overlap+(one-overlap));
  }



  return 0;
}
