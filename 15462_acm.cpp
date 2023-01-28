#include<bits/stdc++.h>
using namespace std;

int n, ans = 0, c = 0;
vector<int> shuffle_;
vector<int> adj[100001];
int check[100001];
map<int, int> finished;

void dfs(int here){
  c++;
  if(check[here]){
    ans += (c - check[here]);
    c--;
    return;
  }
  check[here] = c;
  for(auto &p : adj[here]){
    if(!finished[p]) dfs(p);
  }
  finished[here] = 1;
  return;
}

int main(){

  memset(check, 0, sizeof(check));
  cin>>n;
  shuffle_ = vector<int>(n+1,0);
  for(int i = 1; i <= n; i++){
    cin>>shuffle_[i];
    adj[i].push_back(shuffle_[i]);
  }
  for(int i = 1; i <= n; i++){
    if(!check[i]){
      memset(check,0,sizeof(check));
      dfs(i);
    }
  }
  cout<<ans<<'\n';

  return 0;
}
