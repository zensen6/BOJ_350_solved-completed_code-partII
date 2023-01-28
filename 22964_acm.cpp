#include<bits/stdc++.h>
#define MOD 998244353LL
using namespace std;

typedef unsigned long long ll;
ll n,k,x;

ll mod(ll x){
  if(x<0) return x+MOD;
  return x%MOD;
}

ll power(ll x, ll y){
  if(y==0) return 1ULL;
  else if(y==1ULL) return x;
  else{
    ll tmp = power(x,y>>1ULL);
    if(y&1ULL){
      return mod(mod(x*tmp)*tmp);
    }else{
      return mod(tmp*tmp);
    }
  }
}

int main(){

  cin>>n>>k>>x;
  ll sq = mod((mod(x*(x+1)/2))*(mod(x*(x+1)/2)));
  ll sqX = power(x,2*k-2);
  ll sqXN = power(x,n-k);
  for(int i=0;i<n-k+1;i++)
    cout<<mod(mod(mod(sq*sqX)*sqXN)*k)<<" ";
  cout<<'\n';
  return 0;
}
