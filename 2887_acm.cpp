#include<bits/stdc++.h>
#define MAX 2000000001
using namespace std;

int n,x,y,z,parent[100001];
vector<pair<pair<int,int>,pair<int,int>>> arr;
vector<pair<int,pair<int,int>>> Edge;
vector<pair<int,int>> cx,cy,cz;

int find(int x){
  if(x==parent[x]) return x;
  return parent[x] = find(parent[x]);
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

bool comp(pair<int,int> &a, pair<int,int> &b){
  if(a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}



bool compEdge(pair<int,pair<int,int>>&a, pair<int,pair<int,int>> &b){
  return a.first < b.first;
}


int main(){

  cin>>n;
  if(n == 1){
    cout<<0<<'\n';
    return 0;
  }
  for(int i = 0 ; i < n; i++){
    cin>>x>>y>>z;
    cx.push_back({x,i});
    cy.push_back({y,i});
    cz.push_back({z,i});
  }
  sort(cx.begin(), cx.end(), comp);

  for(int i = 0; i < n-1; i++){
    Edge.push_back({abs(cx[i].first - cx[i+1].first),{cx[i].second,cx[i+1].second}});
    Edge.push_back({abs(cx[i+1].first - cx[i].first),{cx[i+1].second,cx[i].second}});
  }
  sort(cy.begin(), cy.end(), comp);
  for(int i = 0; i < n-1; i++){
    Edge.push_back({abs(cy[i].first - cy[i+1].first),{cy[i].second,cy[i+1].second}});
    Edge.push_back({abs(cy[i+1].first - cy[i].first),{cy[i+1].second,cy[i].second}});
  }
  sort(cz.begin(), cz.end(), comp);
  for(int i = 0; i < n-1; i++){
    Edge.push_back({abs(cz[i].first - cz[i+1].first),{cz[i].second,cz[i+1].second}});
    Edge.push_back({abs(cz[i+1].first - cz[i].first),{cz[i+1].second,cz[i].second}});
  }
  sort(Edge.begin(), Edge.end(), compEdge);
  int l = Edge.size(), ans = 0;
  for(int i = 0; i < n; i++) parent[i] = i;
  for(int i = 0 ; i < l; i++){
    int u = Edge[i].second.first, v = Edge[i].second.second, cost = Edge[i].first;

    if(find(u) != find(v)){
      Union(u,v);
      ans += cost;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
