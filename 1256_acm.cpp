#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
#define MAX 1000000001LL

using namespace std;

typedef long long ll;
int n,m,k;
ll d[202][202];

void makeCombi(){
  for(int i = 1; i < 202; i++){
    d[i][i] = 1LL;
    d[i][0] = 1LL;
  }
  for(int i = 2; i < 202; i++){
    for(int j = 1; j < i; j++){
      d[i][j] = min<ll>(MAX, d[i-1][j-1] + d[i-1][j]);
    }
  }
  return;
}

string proc(int skip, int n_, int m_){

  string ret = "";
  if(n_ == 0){
    for(int i = 0; i < m_; i++) ret += "z";
    return ret;
  }else if(m_ == 0){
    for(int i = 0; i < n_; i++) ret += "a";
    return ret;
  }
  if(skip < d[n_+m_-1][n_-1]){
    ret = "a";
    ret += proc(skip, n_-1, m_);
  }else{
    ret = "z";
    ret += proc(skip - d[n_+m_-1][n_-1], n_, m_-1);
  }
  return ret;
}

int main(){

  memset(d,0,sizeof(d));
  makeCombi();
  cin>>n>>m>>k;
  if(k > d[n+m][m]) cout<<-1<<'\n';
  else cout<<proc(k-1,n,m)<<'\n';

  return 0;
}
