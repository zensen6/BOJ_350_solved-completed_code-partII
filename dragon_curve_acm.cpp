#include<bits/stdc++.h>
#define MAX 1000000001
using namespace std;

int tc,n,p,l, d[51];
string X_CURVE = "X+YF", Y_CURVE = "FX-Y";

string go(int generation, int kth, string str){
  if(generation == 0){
    return str.substr(kth,1);
  }
  for(int i = 0 ; i < str.length(); i++){
    if(str[i] == 'X' && kth <= d[generation]-1){
      return go(generation-1, kth, X_CURVE);
    }else if(str[i] == 'Y' && kth <= d[generation]-1){
      return go(generation-1, kth, Y_CURVE);
    }else if(str[i] == 'Y' || str[i] == 'X'){
      kth -= (d[generation]);
    }else if(kth > 0){
      kth -= 1;
    }else{
      return str.substr(i,1);
    }
  }
  return "#";
}

int main(){
  memset(d,0,sizeof(d));
  d[1] = 4;
  for(int i = 2; i <= 50; i++){
    d[i] = min(MAX,2*d[i-1]+2);
  }
  cin>>tc;
  while(tc--){
    cin>>n>>p>>l;
    string x = "", str = "FX";
    for(int i = p-1; i <= p+l-2; i++){
      x += go(n,i,str);
    }
    cout<<x<<'\n';
  }

  return 0;
}
