#include<bits/stdc++.h>
#define MOD 987654321LL
using namespace std;

typedef long long ll;
ll d[10001];
int main(){

  int n;
  cin>>n;
  memset(d,0,sizeof(d));
  if(n&1) cout<<0<<'\n';
  else{
    d[2] = 1;
    d[4] = 2;
    for(int i=6; i<=n; i+=2){
      d[i] = (2*d[i-2])%MOD;
      for(int j=2; j<=i-4; j+=2){
        d[i] += (d[j]*d[i-j-2]);
        d[i] %= MOD;
      }
    }
    cout<<d[n]<<'\n';
  }

  return 0;
}
