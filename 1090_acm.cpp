#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int n,x,y;
vector<pair<int,int>> pos, virpos, sort_virpos[2500];
pair<int,int> pivot;
map<pair<int,int>,int> m;
bool comp(pair<int,int> a, pair<int,int> b){
  return abs(a.first-pivot.first)+abs(a.second-pivot.second) < abs(b.first-pivot.first)+abs(b.second-pivot.second);
}
int dist(pair<int,int> a, pair<int,int> b){
  return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(){

  int max_ = 0;
  cin>>n;
  for(int i = 0 ; i < n; i++){
    cin>>x>>y;
    m[{x,y}]++;
    max_ = max(max_,m[{x,y}]);
    pos.push_back({x,y});
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      virpos.push_back({pos[i].first,pos[j].second});
    }
  }
  for(int i = 0; i < n*n; i++){
    for(int j = 0 ; j < n; j++){
      sort_virpos[i].push_back(pos[j]);
    }
  }
  for(int i = 0; i < n*n; i++){
    pivot = virpos[i];
    sort(sort_virpos[i].begin(),sort_virpos[i].end(),comp);
  }
  for(int k = 0; k < n; k++){
    if(max_ >= k+1) cout<<0<<" ";
    else{
      int min_ = MAX;
      for(int i = 0 ; i < n*n; i++){
        int tot = 0;
        for(int l = 0 ; l < k+1; l++){
          tot += dist(virpos[i], sort_virpos[i][l]);
        }
        min_ = min(min_,tot);
      }
      cout<<min_;
      if(k<n-1) cout<<" ";
    }
  }

  return 0;
}
