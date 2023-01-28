#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int n;
int d[1000001];

int game(int state){

  int &ret = d[state];
  if(ret!=-2) return ret;

  int ans=MAX;

  string x = to_string(state);
  int s = x.length();
  for(int l=1;l<=s-1;l++){
    for(int i=0;i<=s-l;i++){
      string sub = x.substr(i,l);
      if(sub[0] != '0'){
        if(game(state - stoi(sub)) == -1){
          ans = min(ans, stoi(sub));
        }
      }
    }
  }
  if(ans != MAX){
    return ret = ans;
  }else return ret = -1;
}



int main(){

  for(int i=0;i<1000001;i++){
    d[i] = -2;
  }
  cin>>n;
  cout<<game(n)<<'\n';


  return 0;
}
