#include<bits/stdc++.h>
using namespace std;

bool comp(pair<double,int> &a, pair<double,int> &b){
  if(a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int len = stages.size(),arr[501];
    memset(arr,0,sizeof(arr));
    for(int i = 0 ; i < len ; i++){
      arr[stages[i]]++;
    }
    vector<pair<double,int>> a_;
    for(int i = 1; i <= N ; i++){
      if(!len) a_.push_back({0,i});
      else a_.push_back({(arr[i]/(double)len),i});
      len -= arr[i];
    }
    sort(a_.begin(),a_.end(),comp);
    for(auto &p: a_){
      answer.push_back(p.second);
    }
    return answer;
}


int main(){

  int n,l;
  cin>>n>>l;
  vector<int> stages(l,0);
  for(int i = 0 ; i < l; i++){
    cin>>stages[i];
  }
  auto p = solution(n,stages);
  for(auto k: p){
    cout<<k<<" ";
  }
  cout<<'\n';

  return 0;
}
