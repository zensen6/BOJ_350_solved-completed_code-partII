#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
ll d[5001][5001],d_[5001];
int n,m,p[5001];
int g;

int Function_(int x){
  if(x==p[x]) return x;
  return p[x] = Function_(p[x]);
}

void MERGE_(int x, int y){
  if(Function_(x)!=Function_(y)){
    int x1=p[x],y1=p[y];
    g--;
    if(x1<y1){
      p[y]=x1;
      Function_(x);
    }else{
      p[x]=y1;
      Function_(y);
    }
  }
  return;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  g=n;
  for(int i=1;i<=n;i++){
    p[i]=i;
  }
  for(int k=1;k<=n;k++){
    d[k][1]=1LL;
  }
  for(int k=2;k<=n;k++){
    for(int j=2;j<=k;j++){
      d[k][j]=((j*d[k-1][j])%MOD+d[k-1][j-1])%MOD;
    }
  }
  for(int k=1;k<=n;k++){
    for(int j=1;j<=k;j++){
      d_[k] += d[k][j];
      d_[k] %= MOD;
    }
  }
  for(;m--;){
    int a,b;
    cin>>a>>b;
    MERGE_(a,b);
    cout<<d_[g]%MOD<<'\n';
  }


  return 0;
}
