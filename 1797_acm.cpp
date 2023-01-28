#include<bits/stdc++.h>
using namespace std;

int n;

bool comp(pair<int,int> &a, pair<int,int> &b){
  return a.second < b.second;
}
bool comp1(pair<int,int> &a, pair<int,int> &b){
  if(a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}


map<int,int> ranking; //(25 -> n-1)

int main(){
  cin>>n;
  vector<pair<int,int>> arr(n), rearr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i].first>>arr[i].second;
  }
  sort(arr.begin(),arr.end(),comp);
  int r = 0;
  vector<pair<int,int>> s(n), res(n);
  for(int i=0;i<n;i++){
    ranking[i] = arr[i].second;
    rearr[i].first = (arr[i].first == 0? 1:-1);
    rearr[i].second = arr[i].second;
    if(i==0){
      s[i].first=rearr[i].first;
    }else{
      s[i].first=s[i-1].first+rearr[i].first;
    }
    s[i].second=i;
  }
  res = s;
  sort(res.begin(),res.end(),comp1);
  map<int,int> possi;
  for(auto &p: res){
    possi[p.first] = 1;
  }
  vector<int> res_(n,0);
  for(int i=0;i<n;i++) res_[i] = res[i].first;
  int ans = 0;
  for(auto &p:possi){
    if(p.first == 0){
      int l=upper_bound(res_.begin(),res_.end(),p.first) - res_.begin()-1;
      ans = max(ans,ranking[res[l].second]-arr[0].second);
    }
    int l=lower_bound(res_.begin(),res_.end(),p.first) - res_.begin();
    int r=upper_bound(res_.begin(),res_.end(),p.first) - res_.begin()-1;
    if(l==r) continue;
    ans = max(ranking[res[r].second]-ranking[res[l].second+1],ans);
  }

  cout<<ans<<'\n';
  return 0;
}
