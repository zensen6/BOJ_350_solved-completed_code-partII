#include<bits/stdc++.h>
#define MAX 100000000000000LL
using namespace std;

typedef long long ll;
ll n,M;
ll d[301][100001];
vector<ll> a,b;
ll proc(int index, ll m){
  ll &ret = d[index][m];
  if(ret != MAX) return ret;
  if(index == n){
    if(m==M) return ret=0;
    else return MAX;
  }
  ret = MAX;
  if(index==0){
    if(m+a[index]<=M) ret = min<ll>(ret,proc(index+1,m+a[index])+b[index]);
    ret = min<ll>(ret,proc(index+1,m));
  }else{
    if(m+a[index]<=M){
      ret = min<ll>(ret,proc(index+1,m+a[index])+b[index]);
    }
    if(m+a[index]-1LL<=M){
      ret = min<ll>(ret,proc(index+1,m+a[index]-1LL)+b[index]);
    }
    ret = min<ll>(ret,proc(index+1,m));
  }
  return ret;
}

int main(){

  for(int i=0;i<301;i++){
    for(int j=0;j<100001;j++){
      d[i][j] = MAX;
    }
  }
  cin>>n;
  a = vector<ll> (n,0);
  b = vector<ll> (n,0);
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
    a[i]--;
  }
  cin>>M;
  proc(0,0);
  ll ans = d[0][0];
  if(ans==MAX) cout<<-1<<'\n';
  else cout<<ans<<'\n';

  return 0;
}
