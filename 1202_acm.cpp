#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k;
vector<pair<int,int>> diamond;
vector<int> C;

struct comp{
  bool operator()(pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second;
  }
};

int main(){

  cin>>n>>k;
  diamond = vector<pair<int,int>>(n);
  C = vector<int>(k,0);
  for(int i=0;i<n;i++){
    cin>>diamond[i].first>>diamond[i].second;
  }
  for(int i=0;i<k;i++){
    cin>>C[i];
  }
  sort(C.begin(),C.end());
  sort(diamond.begin(),diamond.end());
  priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
  int l=0;
  ll ans = 0;
  for(int i=0;i<k;i++){
    while(l<n){
      if(diamond[l].first <= C[i]){
        pq.push(diamond[l]);
        l++;
      }else break;
    }
    if(pq.size()){
      ans += pq.top().second;
      pq.pop();
    }
  }
  cout<<ans<<'\n';

  return 0;
}
