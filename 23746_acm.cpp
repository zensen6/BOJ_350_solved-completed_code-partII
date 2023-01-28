#include<bits/stdc++.h>
using namespace std;

int n,s,e;
string x,ans="",t;
char a;
map<char,string>m;

int main(){

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>t>>a;
    m[a] = t;
  }
  cin>>x;
  cin>>s>>e;
  for(auto &p:x) ans+=m[p];
  //cout<<ans<<'\n';
  for(int i=s-1;i<=e-1;i++) cout<<ans[i];
  cout<<'\n';
  return 0;
}
