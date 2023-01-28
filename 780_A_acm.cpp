#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int tc;
ll a, b;

int main(){

  cin>>tc;
  while(tc--){
    cin>>a>>b;
    if(a){
      cout<<2*b+a+1<<'\n';
    }else{
      cout<<1<<'\n';
    }
  }



  return 0;
}
