
#include<bits/stdc++.h>
using namespace std;

int parent[100001], n,q,x1,x2,y,s,f;
vector<pair<pair<int,int>,pair<int,int>>> v;

int find(int x){
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

bool comp(pair<pair<int,int>,pair<int,int>> &a, pair<pair<int,int>,pair<int,int>> &b){
  if(a.first.first == b.first.first) return a.first.second < b.first.second;
  return a.first.first < b.first.first;
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  for(int i = 0; i < n; i++){
    cin>>x1>>x2>>y;
    v.push_back({{x1,x2},{y,i}});
  }
  sort(v.begin(),v.end(),comp);
  bool flag = false;
  int right = 0, lastindex;
  for(int i = 0 ; i < n; i++) parent[i] = i;

  for(auto &p : v){
    if(!flag){
      right = p.first.second;
      lastindex = p.second.second;
      flag = true;
    }else{
      if(p.first.first <= right){
        Union(p.second.second,lastindex);
        find(p.second.second);
        find(lastindex);
        lastindex = p.second.second;
        right = max(right, p.first.second);
      }else{
        lastindex = p.second.second;
        right = p.first.second;
      }
    }
  }

  while(q--){
    cin>>s>>f;
    if(s==f || find(s-1)!=find(f-1)){
      cout<<0<<'\n';
    }else{
      cout<<1<<'\n';
    }
  }
  return 0;

}
