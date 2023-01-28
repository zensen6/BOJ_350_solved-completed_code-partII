#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int arr[200010] ,n;
ll ans = 0;
ll d[200010];
vector<int> node[200010];
int children[200010];
int root;

int dfs(int here){
  if(node[here].size() == 0){
    children[here] = 0;
    return 1;
  }
  int ret = 0;
  for(auto &p: node[here]){
    ret += dfs(p);
  }
  children[here] = ret;
  return ret + 1;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    if(arr[i] == 0){
      root = i;
      continue;
    }
    node[arr[i]].push_back(i);
  }
  dfs(root);
  for(int i=1;i<=n;i++){
    d[i]++; // x = i, y = i -> lca = i
    d[i] += 2LL*children[i]; // x = i, y = all children of i, symmetry -> *2
    for(auto &child:node[i]){
      ll lest = children[i] - children[child] - 1;
      d[i] += (lest * (children[child] + 1));
    }
  }


  int even = false;
  ll e = 0, o = 0;
  for(int i=1;i<=n;i++){
    if(!even){
      o += (i)*((d[i]+1)>>1);
      e += (i)*(d[i]>>1);
      even = ((d[i]&1) ? true:false);
    }else{
      e += (i)*((d[i]+1)>>1);
      o += (i)*(d[i]>>1);
      even = ((d[i]&1) ? false:true);
    }
  }

  cout<<e<<" "<<o<<'\n';
  return 0;
}
