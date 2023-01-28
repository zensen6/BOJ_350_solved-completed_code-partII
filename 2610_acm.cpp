#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

int d[101][101], c = 0;
int group[101], groupcount[101];
bool check[101];
vector<int> adj[101];
int n,k,x,y;

void dfs(int here){
  check[here] = true;
  group[here] = c;
  groupcount[c]++;
  for(auto& p: adj[here]){
    if(!check[p]) dfs(p);
  }
  return;
}

int main(){

  memset(check, false, sizeof(check));
  memset(group, -1, sizeof(group));
  memset(groupcount, 0, sizeof(groupcount));
  for(int i = 0; i < 101; i++){
    for(int j = 0; j < 101; j++){
      d[i][j] = MAX;
    }
  }
  cin>>n;
  cin>>k;
  for(int i = 0 ; i < 101; i++) d[i][i] = 0;
  for(int i = 0 ; i < k; i++){
    cin>>x>>y;
    d[x][y] = 1;
    d[y][x] = 1;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(check[i] == false){
      dfs(i);
      c++;
    }
  }
  cout<<c<<'\n';
  vector<int> ans;
  for(int g = 0; g < c; g++){
    int a = 1000001, index;
    for(int i = 1; i <= n; i++){
      int b = 0;
      for(int j = 1; j <= n; j++){
        if(group[i] == g && group[i] == group[j] && i!=j){
          b = max(b, d[i][j]);
        }
      }
      if(b>0 && b < a){
        a = min(a,b);
        index = i;
      }else if(group[i] == g && groupcount[group[i]] == 1){
        index = i;
      }
    }
    ans.push_back(index);
  }
  sort(ans.begin(),ans.end());
  for(auto &p: ans)cout<<p<<'\n';

  return 0;
}
