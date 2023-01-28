#include<bits/stdc++.h>
using namespace std;

int n,m,v,c,k,len;
int d[2020][10001];
vector<pair<int,int>> option;

int go(int index, int weight){
  int &ret=d[index][weight];
  if(ret != -1) return ret;
  if(index == len) return ret = 0;
  ret = 0;
  int add_w = option[index].first, add_happy = option[index].second;
  if(weight - add_w >= 0) ret = max(ret, go(index+1,weight-add_w)+add_happy);
  ret = max(ret, go(index+1,weight));
  return ret;

}

int main(){

  memset(d,-1,sizeof(d));
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>v>>c>>k;
    for(int j=k;j>0;j>>=1){
      int u=j-(j>>1);
      option.push_back({u*v,u*c});
    }
  }
  len = option.size();
  cout<<go(0,m)<<'\n';


  return 0;
}
