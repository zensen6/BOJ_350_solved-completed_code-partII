#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
ll N,m,M,K;
ll f[1000002];

ll fast_power(ll x, ll p){
  if(p == 1LL) return x;
  if(p == 0) return 1LL;
  ll tmp = fast_power(x,p>>1LL) % MOD;
  if(p&1LL){
    return (((tmp*tmp)%MOD)*x)%MOD;
  }
  return (tmp*tmp)%MOD;
}

int main(){

  cin>>N>>m>>M>>K;
  f[1] = 1LL, f[0] = 1LL;
  for(int i = 2; i <= 1000000; i++){
    f[i] = (i*f[i-1])%MOD;
  }

  //ll A = d[N+K-N*m-1][K-N*m], inf = K-N*m, s = 0;
  ll A = (f[N+K-N*m-1]*(fast_power((f[N-1]*f[K-N*m])%MOD,MOD-2LL)%MOD))%MOD;
  ll inf = K-N*m, s = 0;
  for(ll i = 0; i <= N; i++){
    if(i*(M-m)+i <= inf && inf <= (i+1LL)*(M-m)+i){
      //s += (d[N][i]*d[N+K-N*m-i*(M-m+1)-1][K-N*m-i*(M-m+1)])%MOD;
      ll s1 = (f[N+K-N*m-i*(M-m+1)-1LL]*(fast_power((f[N-1]*f[K-N*m-i*(M-m+1)])%MOD, MOD-2LL))%MOD)%MOD;
      ll s2 = (f[N] * (fast_power((f[N-i]*f[i])%MOD,MOD-2LL))%MOD)%MOD;
      s += (s1*s2)%MOD;
      s %= MOD;
      break;
    }
  }
  cout<<(A-s)%MOD<<'\n';


  return 0;

}
