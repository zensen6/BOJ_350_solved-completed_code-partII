#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k,u,v,w,x,p[1001];
vector<int> elec;
vector<pair<int,pair<int,int>>> edge;

map<int,int> m_;

int Find(int x){
  if(p[x]==x) return x;
  return p[x] = Find(p[x]);
}

void Union(int x, int y){
  int x1=p[x], y1=p[y];
  if(x1<y1){
    p[y1]=x1;
    Find(y);
  }else{
    p[x1]=y1;
    Find(x);
  }
  return;
}

int main(){

  cin>>n>>m>>k;
  for(int i=0;i<k;i++){
    cin>>x;
    m_[x]=1;
    elec.push_back(x);
  }
  for(int i=0;i<m;i++){
    cin>>u>>v>>w;
    edge.push_back({w,{u,v}});
    edge.push_back({w,{v,u}});
  }

  for(int i=1;i<=n;i++) p[i]=i;
  sort(edge.begin(),edge.end());
  ll ans=0;
  for(auto &e:edge){
    int cost=e.first, from=e.second.first, to=e.second.second;
    if(Find(from)!=Find(to)&&(!m_[Find(from)]||!m_[Find(to)])){
      if(m_[Find(from)]){
        m_[Find(to)]=1;
      }
      if(m_[Find(to)]){
        m_[Find(from)]=1;
      }
      ans+=cost;
      Union(from,to);
    }
  }
  cout<<ans<<'\n';

  return 0;
}
