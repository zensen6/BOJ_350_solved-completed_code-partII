#include<bits/stdc++.h>
using namespace std;

int n,x;
priority_queue<int, vector<int>, greater<int>> pq;
list<int> l;

int main(){

  cin>>n;
  for(int i = 1; i<= n; i++){
    cin>>x;
    if(l.size() == 0) l.insert(x);
    else{
      auto ind = lower_bound(l.begin(),l.end(),x) - l.begin();
      if(x == l.end()){
        l.push_back(x);
      }else{
        l.insert(ind, x);
      }
    }
    auto k = l.begin() + (((i+1)>>1)-1);

    cout<<*k<<'\n';
  }


  return 0;
}
