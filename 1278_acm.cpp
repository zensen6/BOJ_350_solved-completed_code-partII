#include<bits/stdc++.h>
using namespace std;

int n;

int two(int state){
  int i=0;
  while(state>1){
    state>>=1;
    i++;
  }
  return i;
}

vector<int> func(int index){
  if(index == 1){
    vector<int> ans;
    ans.push_back(1<<1);
    return ans;
  }
  vector<int> prev = func(index-1);
  vector<int> next = prev;
  reverse(next.begin(),next.end());
  for(auto &p: next){
    p += (1<<index);
  }
  next.push_back(1<<index);
  vector<int> ans;
  for(auto &p: prev)ans.push_back(p);
  for(auto &p: next)ans.push_back(p);
  return ans;
}


int main(){

  cin>>n;
  vector<int> ans = func(n);
  int len = ans.size();
  cout<<(1<<n)-1<<'\n';
  cout<<1<<'\n';
  for(int i=1;i<len;i++) cout<<two(abs(ans[i]-ans[i-1]))<<'\n';
  cout<<two(ans[len-1])<<'\n';
  return 0;
}
