#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int s,n,k,r1,r2,c1,c2,arr[51][51];

void proc(int power, bool isblack, int Rl, int Rr, int Cl, int Cr){

  if(power == 0){
    for(int i = Rl; i < Rr; i++){
      for(int j = Cl; j < Cr; j++){
        if(i>=r1 && i<=r2 && j>=c1 && j<=c2){
          arr[i-r1][j-c1] = (isblack? 1 : ((i-Rl>=((n-k)/2) && Rr-i>((n-k)/2)) && j-Cl>=((n-k)/2) && Cr-j>((n-k)/2) ? 1:0));
        }
      }
    }
    return;
  }
  int p = pow(n,power);
  for(int i = Rl; i<Rr; i+=p){
    for(int j = Cl; j<Cr; j+=p){
      if(((i<=r1&&i+p-1>=r1)||(i<=r2&&i+p-1>=r2)||(r1<=i&&i+p-1<=r2)) && ((j<=c1&&j+p-1>=c1)||(j<=c2&&j+p-1>=c2)||(j>=c1&&j+p-1<=c2))){
        if(!isblack && (i-Rl)/p>=((n-k)/2) && (Rr-i)/p>((n-k)/2) &&(j-Cl)/p>=((n-k)/2) && (Cr-j)/p>((n-k)/2)){
          proc(power-1, true, i, i+p, j, j+p);
        }else if(!isblack){
          proc(power-1, false, i, i+p, j, j+p);
        }else{
          proc(power-1, true, i, i+p, j, j+p);
        }
      }
    }
  }
  return;
}

int main(){

  memset(arr,-1,sizeof(arr));
  scanf("%d %d %d %d %d %d %d",&s,&n,&k,&r1,&r2,&c1,&c2);
  if(s==0){
    printf("0\n");
    return 0;
  }else{
    proc(s-1, false, 0,pow(n,s),0,pow(n,s));
  }

  for(int i = 0 ; i <= r2-r1; i++){
    for(int j = 0 ; j <= c2-c1; j++){
      printf("%1d",arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
