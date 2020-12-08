#include<bits/stdc++.h>
using namespace std;

int tc,n;
string x, A="abacaba", s;

int f(string & a, int n){
  int c = 0;
  for(int i = 0; i <= n-7; i++){
    if(a.substr(i,7) == A) c++;
  }
  return c;
}

int main(){

  cin>>tc;
  while(tc--){
    cin>>n;
    cin>>x;

    bool done = false;
    for(int i = 0 ; i <= n-7; i++){
      s = x;
      for(int j = 0 ; j < 7; j++){
        if(s[i+j] == '?') s[i+j] = A[j];
      }
      for(auto &p: s){
        if(p == '?') p = 'x';
      }
      if(f(s, n) == 1){
        done = true;
        cout<<"Yes"<<'\n';
        cout<<s<<'\n';
        break;
      }
    }
    if(!done) cout<<"No"<<'\n';
  }
  return 0;
}
