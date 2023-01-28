#include<bits/stdc++.h>
#define MOD 1000000000ULL

using namespace std;

typedef unsigned long long ll;
ll n,m,x,y,w,p[100001],group[100001];
vector<pair<int,pair<int,int>>> edge;
ll s=0,ans=0;

int Find(int x){
  if(p[x]==x) return x;
  return p[x]=Find(p[x]);
}

void Union(int x, int y){
  int x1=p[x], y1=p[y];
  if(x1<y1){
    p[y1]=x1;
    group[x1]+=group[y1];
    Find(y);
  }else{
    p[x1]=y1;
    group[y1]+=group[x1];
    Find(x);
  }
  return;
}

ll mod(ll x){
  if(x<0) return (x+MOD)%MOD;
  return x%MOD;
}

int main(){

  for(int i=1;i<=100000;i++){
    p[i]=i;
    group[i]=1;
  }
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>x>>y>>w;
    s+=w;
    edge.push_back({w,{x,y}});
  }
  sort(edge.begin(),edge.end());
  reverse(edge.begin(),edge.end());
  ll tmp=0;
  for(auto &e: edge){
    int cost=e.first, u=e.second.first, v=e.second.second;
    if(Find(u)!=Find(v)){
      ans+=(mod(group[p[u]]*group[p[v]])*mod(s-tmp));
      ans=mod(ans);
      Union(u,v);
    }
    tmp += cost;
  }
  cout<<ans<<'\n';
  return 0;
}
