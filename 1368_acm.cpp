#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge{
  int from, to, cost;
};

bool cmp(Edge &a, Edge &b){
  return a.cost < b.cost;
}


int drain[302][302], n,x, p[302];
vector<int> arr;
vector<Edge> E;

int Find(int x){
  if(p[x] == x) return x;
  return p[x] = Find(p[x]);
}

void Union(int x, int y){
  int x1=Find(x), y1=Find(y);
  if(x1 < y1){
    p[y1] = x1;
    Find(y);
  }else{
    p[x1] = y1;
    Find(x);
  }
  return;
}

ll kruscal(){
  for(int j=1;j<302;j++) p[j] = j;
  ll res=0;
  int len = E.size();
  for(int j=0;j<len;j++){
    int u=E[j].from, v=E[j].to, cost=E[j].cost;
    if(Find(u) != Find(v)){
      //cout<<u<<" "<<v<<" "<<cost<<'\n';
      res += cost;
      Union(u,v);
    }
  }
  return res;
}

int main(){

  cin>>n;
  arr = vector<int> (n+1);
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>drain[i][j];
      E.push_back({i,j,drain[i][j]});
      E.push_back({j,i,drain[i][j]});
    }
  }
  for(int i=1;i<=n;i++){
    E.push_back({0,i,arr[i]});
  }
  sort(E.begin(),E.end(),cmp);
  ll ans = kruscal();
  cout<<ans<<'\n';


  return 0;
}
