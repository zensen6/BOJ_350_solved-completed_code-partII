#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;

ll n,k,d[4000001];

ll fastpow(ll x, ll y){
  if(y==1LL) return x;
  else if(y==0) return 1LL;
  else if(y&1LL){
    ll tmp = fastpow(x, y>>1)%MOD;
    return (((tmp*tmp)%MOD)*x)%MOD;
  }else{
    ll tmp = fastpow(x, y>>1)%MOD;
    return (tmp*tmp)%MOD;
  }return 0;
}


int main(){
  cin>>n>>k;
  d[0]= 1LL, d[1] = 1LL;
  for(int i = 2; i<=n;i++) d[i] = (d[i-1]*i)%MOD;
  ll A = d[n];
  ll B = (d[k]*d[n-k])%MOD;
  cout<<(A*fastpow(B, MOD-2LL))%MOD<<'\n';

  return 0;
}
