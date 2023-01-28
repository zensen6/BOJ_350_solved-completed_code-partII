#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

bool comp(pair<int,int> &a, pair<int,int> &b){
  if(a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,x,y;
  cin>>n;
  for(int i = 0 ; i < n; i++){
    cin>>x>>y;
    v.push_back({x,y});
  }
  sort(v.begin(), v.end(), comp);
  int sum = 0, right=-1000000000;
  for(auto p:v){
    if(p.first >= right){
      sum += (p.second - p.first);
      right = p.second;
    }else if(p.second >= right){
      sum += (p.second - right);
      right = p.second;
    }
  }
  cout<<sum<<'\n';

  return 0;
}
