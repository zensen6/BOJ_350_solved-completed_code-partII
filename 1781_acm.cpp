#include<bits/stdc++.h>

using namespace std;

int n;

struct comp{
  bool operator()(pair<int,int>&a, pair<int,int>&b){
    return a.second > b.second; // pq는 반대로 작성해야한다.
  }
};

vector<pair<int,int>> v;
priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;



int solve(){
  int ans=0;
  for(auto &p:v){
    if(pq.size() < p.first){
      pq.push(p);
    }else{
      auto f_ = pq.top();
      int deadline = f_.first, value = f_.second;
      if(value < p.second){
        pq.pop();
        pq.push(p);
      }
    }
  }
  while(!pq.empty()){
    ans += pq.top().second;
    pq.pop();
  }
  return ans;
}

int main(){

  cin >> n;
  v.resize(n);

  for (int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;
    v[i] = {a,b};
  }

  sort(v.begin(), v.end());
  cout << solve()<<'\n';
}
