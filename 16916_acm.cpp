#include<bits/stdc++.h>
using namespace std;

string N,H;
int n,m;

vector<int> makepi(){
  vector<int> pi(n,0);
  int begin=1,matched=0;
  while(begin+matched<n){
    if(N[begin+matched]==N[matched]){
      matched++;
      pi[begin+matched-1] = matched;
    }else{
      if(matched==0) begin++;
      else{
        begin += (matched - pi[matched-1]);
        matched = pi[matched-1];
      }
    }
  }
  return pi;
}

int matchornot(){
  vector<int> pi = makepi();
  int begin=0,matched=0;
  while(begin<=m-n){
    if(N[matched]==H[begin+matched]&&matched<n){
      matched++;
      if(matched==n){
        return 1;
      }
    }else{
      if(matched==0) begin++;
      else{
        begin += (matched - pi[matched-1]);
        matched = pi[matched-1];
      }
    }
  }
  return 0;

}


int main(){

  cin>>H;
  cin>>N;
  m=H.length();
  n=N.length();
  if(n>m){
    cout<<0<<'\n';
    return 0;
  }
  cout<<matchornot()<<'\n';

  return 0;
}
