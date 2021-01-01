#include<bits/stdc++.h>
using namespace std;

int n,k,w,v, d[101][100001];
vector<pair<int,int>> bag;

int dp(int index, int weight){
  if(index == n) return 0;
  int &ret = d[index][weight];
  if(ret != -1) return ret;
  ret = 0;
  if(weight + bag[index].first <= k){
    ret = bag[index].second + dp(index+1, weight + bag[index].first);
  }
  ret = max(ret, dp(index+1, weight));
  return ret;
}

int main(){
  cin>>n>>k;

  memset(d,-1,sizeof(d));
  for(int i = 0 ; i < n; i++){
    cin>>w>>v;
    bag.push_back({w,v});
  }
  cout<<dp(0,0)<<'\n';

  return 0;
}
