#include<bits/stdc++.h>
using namespace std;

int pi[5001];

void makepi(const string &x){

  int begin = 1, matched = 0, n = x.length();
  while(begin + matched < n){
    if(x[begin + matched] == x[matched]){
      matched++;
      pi[begin + matched -1] = matched;
    }else{
      if(matched == 0) begin++;
      else{
        begin += (matched - pi[matched -1]);
        matched = pi[matched -1];
      }
    }
  }
}

int main(){

  string x;
  cin>>x;
  int len = x.length(), ans = 0;
  for(int start = 0; start < len; start++){
    memset(pi,0,sizeof(pi));
    makepi(x.substr(start));
    for(int i = 0; i < len - start; i++){
      ans = max(ans, pi[i]);
    }
  }

  cout<<ans<<'\n';
  return 0;
}
