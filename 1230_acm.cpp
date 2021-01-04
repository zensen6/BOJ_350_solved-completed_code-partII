#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int d[1001][1001][2];
string x,y;

int xl,yl;
/*
int proc(int s, int w, int conti){
  int& ret = d[s][w][conti];
  if(ret != INF) return ret;
  if(s == xl && w == yl){
    return ret = 0;
  }else if(s == xl){
    return ret = 1;
  }else if(w == yl){
    return ret = INF;
  }
  if(x[s] == y[w]){
    ret = proc(s+1, w+1, 0);
    if(conti == 1) ret = min(ret, proc(s, w+1, 1));
    else ret = min(ret, 1 + proc(s, w+1, 1));
  }else{
    if(conti == 0) ret = 1 + proc(s, w+1, 1);
    else ret = proc(s, w+1, 1);
  }
  return ret;
}
*/

int proc(){
  for(int s = xl; s >= 1; s--){
    for(int w = yl; w >= 1; w--){
      for(int k = 0; k < 2; k++){
        if(s == xl && w == yl){
          d[s][w][k] = 0;
        }else if(s == xl){
          d[s][w][k] = 1;
        }else if(w == yl){
          d[s][w][k] = INF;
        }
        if(x[s-1] == y[w-1]){
          d[s-1][w-1][k] = min(d[s][w][0], d[s-1][w][1] + (1^k));
        }else{
          d[s-1][w-1][k] = d[s-1][w][1] + (1^k);
        }
      }
    }
  }
  return d[0][0][0];
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 0 ; i < 1001; i++){
    for(int j = 0; j < 1001; j++){
      for(int k = 0 ; k <= 1 ; k++)
      d[i][j][k] = INF;
    }
  }
  getline(cin,x);
  getline(cin,y);

  xl = x.length();
  yl = y.length();

  int ans = proc();
  if(ans >= INF) cout<<-1<<'\n';
  else cout<<ans<<'\n';

  return 0;
}
