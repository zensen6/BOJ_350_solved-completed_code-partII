#include<bits/stdc++.h>
using namespace std;

int main(){

  int n, alpha[26];
  memset(alpha,0,sizeof(alpha));
  string x;
  vector<string> v;
  cin>>n;
  for(int i = 0 ; i < n; i++){
    cin>>x;
    v.push_back(x);
  }
  for(auto &p: v){
    alpha[int(p[0]-'a')]++;
  }
  int c = 0;
  for(int i = 0 ; i < 26; i++){
    if(alpha[i]) c++;
  }
  if(c==1) cout<<1<<'\n';
  else cout<<0<<'\n';

  return 0;
}
