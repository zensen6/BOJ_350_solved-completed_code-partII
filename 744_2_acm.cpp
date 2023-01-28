#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tc,n;
int main(){

  cin>>tc;
  while(tc--){
    cin>>n;
    if(n%9==0) cout<<"TAK"<<'\n';
    else if(n%3==2) cout<<"TAK"<<'\n';
    else if(n%3==0) cout<<"NIE"<<'\n';
    else cout<<"NIE"<<'\n';

  }

  return 0;
}
