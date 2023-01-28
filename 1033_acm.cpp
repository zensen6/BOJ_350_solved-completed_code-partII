#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a,b,p,q,n;
vector<pair<ll,pair<ll,ll>>> adj[11];
ll value[11], ind[11];
bool check[11];

ll gcd(ll x, ll y){
  if(y==0) return x;
  return gcd(y,x%y);
}
ll lcd(ll x, ll y){
  if(x==y) return x;
  return (y*x)/gcd(x,y);
}

ll dfs(ll here){
  ll ans = 1LL;
  for(auto &p: adj[here]){
    if(!check[p.first]){
      check[p.first] = true;
      ans *= p.second.first;
      ans *= dfs(p.first);
    }
  }
  return value[here] = ans;
}

void dfs1(ll here){
  for(auto &p: adj[here]){
    if(!check[p.first]){
      check[p.first] = true;
      value[p.first] = p.second.second*(value[here]/p.second.first);
      dfs1(p.first);
    }
  }
  return;
}

int main(){

  for(int i = 0 ; i < 11; i++) value[i] = 1LL;
  memset(check,false,sizeof(check));
  cin>>n;
  for(int i = 0; i < n-1; i++){
    cin>>a>>b>>p>>q;
    adj[a].push_back({b,{p,q}});
    adj[b].push_back({a,{q,p}});
  }
  int root = 0;
  dfs(root);
  memset(check,false,sizeof(check));
  dfs1(root);
  vector<ll> ans;
  for(int i = 0 ; i < n; i++){
    ans.push_back(value[i]);
  }
  ll G = value[0];

  for(int i = 1 ; i < n; i++){
    G = gcd(G,value[i]);
  }
  for(int i = 0; i < n; i++){
    cout<<value[i]/G<<' ';
  }
  cout<<'\n';
  return 0;
}
