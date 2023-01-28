#include<bits/stdc++.h>
using namespace std;

int n,x,y,d;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;

bool comp(pair<int,int> &a, pair<int,int> &b){
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main(){

  cin>>n;
  for(int i = 0 ; i < n; i++){
    cin>>x>>y;
    v.push_back({min(x,y),max(x,y)});
  }
  cin>>d;
  sort(v.begin(),v.end(), comp);
  int ans = 0;
  for(int i = 0 ; i < n; i++){
    if(v[i].second - d <= v[i].first){
      pq.push(v[i].first);
    }
    if(pq.size() > 0){
      while (pq.size() && pq.top() < v[i].second - d) pq.pop();
      ans = max<long long>(ans, pq.size());
    }
  }
  cout<<ans<<'\n';
  return 0;

}
