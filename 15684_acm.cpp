#include<bits/stdc++.h>
#define END 1000000000
using namespace std;
int n,m,h,a,b;
vector<pair<int,int>> v[11]; // from -> {h,to}

pair<int,int> next_path(pair<int,int> prev){ // {depth, to}
  int to=prev.second, depth=prev.first;
  int index = upper_bound(v[to].begin(),v[to].end(),{depth,11}) - v[to].begin();
  if(v[index].first <= depth){
    return {END,to};
  }
  return v[index];
}

int main(){

  cin>>n>>m>>h;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    v[b].push_back({a,b+1});
    v[b+1].push_back({a,b});
  }
  for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),[](pair<int,int> &a, pair<int,int> &b){
    return a<b;
  });

  //add nothing
  bool nothing=true;
  for(int i=1;i<=n;i++){
    if(!v[i].size()) continue;
    pair<int,int> start = v[i][0];
    while(next_path(start).first != END){
      start = next_path(start);
    }
    if(next_path(start).second!=i){
        nothing=false;
        break;
    }
  }
  if(nothing){
    cout<<0<<'\n';
    return 0;
  }


  return 0;
}
