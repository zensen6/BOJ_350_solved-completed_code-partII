#include<bits/stdc++.h>
using namespace std;

int tc,n,x;
vector<int> v[100001];
int num[100001],group[100001],g=1;

int dfs(int here, int c){
  if(group[here]){
    if(group[here]==g)
      return c-num[here];
    return 0;
  }
  group[here]=g;
  num[here]=c;
  int ret=0;
  for(auto &p:v[here]){
    ret = dfs(p,c+1);
  }
  return ret;
}


int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>tc;
  while(tc--){
    g=1;
    memset(num,0,sizeof(num));
    memset(group,0,sizeof(group));
    for(int i=0;i<100001;i++) v[i].clear();
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>x;
      v[i+1].push_back(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
      if(!group[i]){
        ans += dfs(i,1);
        g++;
      }
    }
    cout<<n-ans<<'\n';
  }


  return 0;
}
