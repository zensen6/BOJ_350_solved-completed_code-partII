#include<bits/stdc++.h>
using namespace std;

int n,m,s,p,x,y;
vector<int> adj[500001],atm,restaurant;
int sccId, sccGroup[500001], visited[500001], counter=0, d[500001],sccMoney[500001], ind[500001];
vector<int> sccGraph[500001];
bool check[500001];

stack<int> st;
int scc(int here){
  st.push(here);
  visited[here] = counter++;
  int ret = visited[here];
  int len = adj[here].size();
  for(int i=0;i<len;i++){
    int next = adj[here][i];
    if(visited[next] == -1){
      ret = min(ret, scc(next));
    }else if(sccGroup[next] == -1){
      ret = min(ret, visited[next]);
    }
  }
  if(ret == visited[here]){
    while(!st.empty()){
      int t = st.top();
      sccGroup[t] = sccId;
      st.pop();
      if(t == here) break;
    }
    sccId++;
  }
  return ret;
}

void dfs(int here){
  check[here] = true;
  for(auto &p:adj[here]){
    if(!check[p]){
      if(sccGroup[p] != sccGroup[here]){
        ind[sccGroup[p]]++;
        sccGraph[sccGroup[here]].push_back(sccGroup[p]);
      }
      dfs(p);
    }
  }
  return;
}


int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(visited,-1,sizeof(visited));
  memset(sccGroup, -1,sizeof(sccGroup));
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    adj[x].push_back(y);
  }
  atm = vector<int>(n+1);
  for(int i=1;i<=n;i++){
    cin>>atm[i];
  }
  cin>>s>>p;
  restaurant = vector<int>(p+1);
  for(int i=0;i<p;i++){
    cin>>restaurant[i];
  }
  for(int v=1;v<=n;v++){
    if(sccGroup[v]==-1) scc(v);
  }


  //
  /*
  for(int v=1;v<=n;v++) cout<<sccGroup[v]<<" ";
  cout<<'\n';
  */
  //


  for(int v=1;v<=n;v++){
    sccMoney[sccGroup[v]] += atm[v];
  }

  //
  /*
  for(int i=0;i<sccId;i++) cout<<sccMoney[i]<<" ";
  cout<<'\n';
  */
  //
  dfs(s);
  //dag
  queue<int> q;
  q.push(sccGroup[s]);
  d[sccGroup[s]] = sccMoney[sccGroup[s]];
  while(!q.empty()){
    int here = q.front();
    q.pop();
    int len = sccGraph[here].size();
    for(int i=0;i<len;i++){
      int next = sccGraph[here][i];
      //
      //cout<<here<<" "<<next<<'\n';
      //cout<<here<<" "<<d[here]<<'\n';
      //
      ind[next]--;
      d[next] = max(d[next],d[here]+sccMoney[next]);
      //
      //cout<<here<<" "<<next<<" "<<d[next]<<'\n';
      //
      if(ind[next]==0){
        q.push(next);
      }
    }
  }
  int ans=0;
  for(int i=0;i<p;i++){
    ans = max(ans,d[sccGroup[restaurant[i]]]);
  }
  cout<<ans<<'\n';

  return 0;
}
