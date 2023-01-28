#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

set<int> d[1<<6];
int n;
vector<int> arr;

bool isPrime(int x){
  if(x==2) return true;
  else if(x<2) return false;
  else for(int i=2;i*i<=x;i++) if(x%i==0) return false;
  return true;
}

set<int> go(int mask){
  set<int> &ret = d[mask];
  if(ret.size()) return ret;
  for(int i=0;i<(1<<n);i++){
    int f = i&mask, s = (~f)&mask;
    if(f==0||s==0) continue;
    go(f);
    go(s);
    for(auto &x:d[f]){
      for(auto &y:d[s]){
        d[mask].insert(x+y);
        d[mask].insert(x-y);
        d[mask].insert(y-x);
        d[mask].insert(x*y);
        if(x!=0) d[mask].insert(y/x);
        if(y!=0) d[mask].insert(x/y);
      }
    }
  }
  return ret;
}


int main(){

  cin>>n;
  arr = vector<int> (n,0);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<n;i++) d[1<<i].insert(arr[i]);
  go((1<<n)-1);
  int ans_min=MAX, ans_max=-1;
  for(auto &p: d[(1<<n)-1]){
    if(isPrime(p)){
      ans_max = max(ans_max, p);
      ans_min = min(ans_min, p);
    }
  }
  if(ans_max==-1) cout<<-1<<'\n';
  else cout<<ans_min<<'\n'<<ans_max<<'\n';
  return 0;
}
