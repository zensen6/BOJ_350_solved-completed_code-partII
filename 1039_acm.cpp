#include<bits/stdc++.h>
using namespace std;

bool inorder(vector<int> &v){
  for(int i = 0 ; i < v.size() -1; i++){
    if(v[i] < v[i+1]) return false;
  }
  return true;
}

int main(){

  string x;
  int n;
  cin>>x;
  cin>>n;
  vector<int> v(x.length(),0);
  int len = x.length();
  if(len == 1){
    cout<<-1<<'\n';
    return 0;
  }
  for(int i = 0 ; i < len ;i++){
    v[i] = (int)(x[i]-'0');
  }

  int c = 0, turn = 0;
  while(c < n && turn < len){
    int max_ = -1, index = -1;
    for(int sw = turn; sw < len; sw++){
      if(v[sw] > max_){
        max_ = v[sw];
        index = sw;
      }
    }
    if(index == turn){
      turn++;
      continue;
    }
    else{
      c++;
      swap(v[turn], v[index]);
    }
    turn++;
    if(inorder(v)) break;
  }
  if((n - c)&1){
    int k = 0;
    for(int i = 0 ; i < len-1; i++){
      if(v[i] == v[i+1]) k++;
    }
    if(len >= 2 && k==0) swap(v[len-1],v[len-2]);
  }
  for(auto p: v) cout<<p;
  cout<<'\n';

  return 0;
}
