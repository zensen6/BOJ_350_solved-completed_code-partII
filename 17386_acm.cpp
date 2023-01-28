#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x1,y_1,x2,y_2,x3,y_3,x4,y_4;

ll cross(ll x1, ll y_1, ll x2, ll y_2){
  return x1*y_2-x2*y_1;
}

int main(){

  cin>>x1>>y_1>>x2>>y_2;
  cin>>x3>>y_3>>x4>>y_4;
  ll resBC,resBD,resDB,resDA;
  resBC=cross(x2-x1,y_2-y_1,x3-x1,y_3-y_1),resBD=cross(x2-x1,y_2-y_1,x4-x1,y_4-y_1);
  resDB=cross(x4-x3,y_4-y_3,x2-x3,y_2-y_3),resDA=cross(x4-x3,y_4-y_3,x1-x3,y_1-y_3);
  if(resBC*resBD < 0 && resDB*resDA < 0) cout<<1<<'\n';
  else cout<<0<<'\n';

  return 0;
}
