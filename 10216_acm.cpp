#include<bits/stdc++.h>
using namespace std;

int tc,x,y,n,r, parent[3001];
vector<pair<pair<int,int>,int>> pos;

int find(int x){
  if(x==parent[x]) return x;
  return parent[x] = find(parent[x]);
}

int dist(pair<int,int> &a, pair<int,int> &b){
  return pow(abs(a.first-b.first),2) + pow(abs(a.second-b.second),2);
}

void Union(int x, int y){
  int x1 = find(x), y1 = find(y);
  if(x1 < y1){
    parent[y1] = x1;
    find(y);
  }else{
    parent[x1] = y1;
    find(x);
  }
  return;
}

int main(){

  cin>>tc;
  while(tc--){
    cin>>n;
    pos.clear();
    for(int i = 0; i < n; i++) parent[i] = i;
    for(int i = 0; i < n; i++){
      cin>>x>>y>>r;
      pos.push_back({{x,y},r});
    }
    for(int i = 0; i < n-1; i++){
      for(int j = i+1; j < n; j++){
        if(find(i) != find(j) && (pos[i].second + pos[j].second)*(pos[i].second + pos[j].second) >= dist(pos[i].first,pos[j].first)){
          //cout<<i<<" "<<j<<'\n';
          Union(i,j);
        }
      }
    }
    set<int> s;
    for(int i = 0; i < n; i++){
      s.insert(find(i));
    }
    cout<<s.size()<<'\n';
  }


  return 0;
}
