#include<bits/stdc++.h>
using namespace std;

int tc, n, w, h;

int main(){

  cin>>tc;
  while(tc--){
    cin>>w>>h>>n;
    int o=1,t=1;
    while(w%2==0){
      w/=2;
      o*=2;
    }while(h%2==0){
      h/=2;
      t*=2;
    }
    if(o*t >=n) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';

  }


  return 0;
}
