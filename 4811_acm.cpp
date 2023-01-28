#include<iostream>
#include<memory.h>
using namespace std;

typedef long long ll;

ll d[62][62];
int n,tc;

int main(){

  memset(d,0,sizeof(d));

  d[0][1] = 1LL;
  for(int i = 1; i <= 61; i++) d[i][0] = 1LL;
  for(int i = 1; i <= 61; i++) d[i][1] = i+1LL;
  for(int l = 60; l >= 1; l--){
    for(int r = 1; r <= 60; r++){
      d[l-1][r] = d[l][r] - d[l+1][r-1];
    }
  }
  while(1){
    cin>>n;
    if(!n) break;
    cout<<d[1][n-1]<<'\n';
  }

  return 0;
}
