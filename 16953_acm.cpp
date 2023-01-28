#include<bits/stdc++.h>
using namespace std;

int a,b;
map<long long,int> m;


int proc(){
  queue<pair<long long,int>>q;
  q.push({a,0});
  m[a]=1;
  while(!q.empty()){
    auto &t=q.front();
    q.pop();
    if(t.first==b) return t.second;
    if((t.first<<1) > b) continue;
    else{
      if(t.first*10+1 <= b &&m[t.first*10+1]==0){
        m[t.first*10+1]=1;
        //cout<<t.first*10+1<<'\n';
        q.push({t.first*10+1,t.second+1});
      }
      if(m[t.first*2]==0){
        m[t.first*2]=1;
        //cout<<t.first*2<<'\n';
        q.push({t.first*2,t.second+1});
      }
    }
  }
  return -1;

}

int main(){
  cin>>a>>b;
  int res = proc();
  res = (res == -1? -1: res+1);
  cout<<res<<'\n';
}
