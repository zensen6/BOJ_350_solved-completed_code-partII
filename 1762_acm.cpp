#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,ans=0;

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  vector<set<int>> v(n+1);
  vector<vector<int>> adj(n+1);
  for(int i=0;i<m;i++){
    cin>>x>>y;
    v[min(x,y)].insert(max(x,y));
    adj[min(x,y)].push_back(max(x,y));
  }

  for(int i=1;i<=n;i++){
    int len = adj[i].size();
    for(int j=0;j<len;j++){
      vector<int> intersect;
      set_intersection(v[adj[i][j]].begin(),v[adj[i][j]].end(),v[i].begin(),v[i].end(),back_inserter(intersect));
      ans += intersect.size();
    }
  }
  cout<<ans<<'\n';

  return 0;
}
