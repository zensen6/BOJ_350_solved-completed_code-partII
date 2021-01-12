#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int parent[200001];
bool check[200001];
bool exists[200001];
int n,q,x,y;
int s,f;
set<int> se;
int query(int i, int j){

  if(parent[i] == parent[j]) return 1;
  else return 2;

}

void init(int here){
  check[here] = true;
  for(auto&p : adj[here]){
    cout<<p;
    if(!check[p]) init(p);
    else{
      s = here, f = p;
      return;
    }
  }
  return;
}

bool dfs(int here){

  bool done = false;
  check[here] = true;
  if(here == f){
    se.insert(f);
    exists[here] = true;
    return true;
  }
  for(auto &p:adj[here]){
    if(!check[p]){
      //cout<<p<<"\n";
      if(dfs(p)){
        //cout<<here<<'\n';
        se.insert(here);
        exists[here] = true;
        done = true;
      }
    }else if(p == f){
      se.insert(here);
      exists[here] = true;
      done = true;
    }
  }
  return done;
}

void dfs2(int root, int here){
  check[here] = true;
  for(auto& p : adj[here]){
    if(!check[p]){
      if(!exists[p]){
        //cout<<"go"<<p<<'\n';
        parent[p] = root;
        dfs2(root, p);
      }
    }
  }
  return;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(parent,-1,sizeof(parent));
  memset(check, false, sizeof(check));
  memset(exists,false,sizeof(exists));
  cin>>n>>q;
  for(int i = 0 ; i < n; i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  init(1);
  memset(check, false, sizeof(check));
  cout<<"s,f: "<<s<<" "<<f<<'\n';
  dfs(s);
  memset(check,false,sizeof(check));

  for(auto it = se.begin(); it!=se.end();it++){
    cout<<*it<<" ";
  }
  cout<<'\n';

  for(auto it = se.begin(); it!=se.end();it++){
    parent[*it] = *it;
    dfs2(*it,*it);
  }

  for(int i = 1; i <= n; i++) cout<<parent[i]<<' ';

  for(int i = 0 ; i < q; i++){
    cin>>x>>y;
    cout<<query(x,y)<<'\n';
  }


  return 0;
}
