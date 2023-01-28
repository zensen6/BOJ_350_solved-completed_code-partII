#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int T,t,n,m,s,g,h,a,b,d,x;
vector<pair<int,int>> adj[2001];
vector<int>ans;
map<int,int> save;
int dist[2001];
bool check[2001];
set<int> s_,s__;

void dijkstra(){
  memset(check, false, sizeof(check));
  for(int i = 1 ; i <= n; i++) dist[i] = INF;
  dist[s] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,s});
  while(!pq.empty()){
    auto k = pq.top();
    pq.pop();
    int cost = k.first, target = k.second;
    if(cost > dist[target]) continue;
    for(auto l: adj[target]){
      int c = l.second, to = l.first;
      if(dist[target] + c < dist[to]){
        dist[to] = dist[target] + c;
        pq.push({dist[to], to});
      }
    }
  }
  return;

}
void dfs(int from, int here){

  if(s_.find(here) != s_.end()){
    s__.insert(here);
  }
  for(auto &p: adj[here]){
    int to = p.first, cost = p.second;
    if(dist[here] + cost == dist[to] && !check[to]){
      check[to] = true;
      dfs(here, to);
    }
  }
  return;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>T;
  while(T--){
    for(int i = 0 ; i < 2001; i++) adj[i].clear();
    ans.clear();s_.clear();
    s__.clear();save.clear();
    cin>>n>>m>>t;
    cin>>s>>g>>h;
    save[g] = 1, save[h] = 1;
    for(int i = 0 ; i < m; i++){
      cin>>a>>b>>d;
      adj[a].push_back({b,d});
      adj[b].push_back({a,d});
    }
    for(int i = 0 ; i < t; i++){
      cin>>x;
      s_.insert(x);
    }
    dijkstra();
    for(auto p: adj[g]){
      if(p.second + dist[g] == dist[h]){
        dfs(h,h);
        break;
      }
    }
    for(auto p: adj[h]){
      if(p.second + dist[h] == dist[g]){
        dfs(g,g);
        break;
      }
    }
    set<int>::iterator it;
    for(it = s__.begin(); it!=s__.end(); it++){
      ans.push_back(*it);
    }
    sort(ans.begin(),ans.end());
    for(auto &p: ans) cout<<p<<" ";
    cout<<'\n';
  }


  return 0;
}
