#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int tc,n;
priority_queue<ll,vector<ll>,greater<ll>> pq;


map<ll,ll> m, order;

void proc(){
  ll start=1LL,index=0;
  queue<pair<ll,int>> q;
  q.push({1,0});
  int c=1;
  while(c<=10000000){
    auto t = q.front();
    q.pop();
    ll here = t.first;
    index = t.second;
    if(m[here]==0){
      m[here]=1;
      c+=1;
      pq.push(here);
      q.push({2*here+1,index+1});
      q.push({3*here+1,index+1});
    }
  }
  c=1;
  while(!pq.empty()){
    order[c++]=pq.top();
    pq.pop();
  }
  return;
}


int main(){

  cin>>tc;
  proc();
  while(tc--){
    cin>>n;
    cout<<order[n]<<'\n';
  }


}
