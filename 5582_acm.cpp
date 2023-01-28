#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;

string x,y;
int len1, len2, d[4002][4002];

/*
int proc(int index1, int index2){
  if(index1 == len1 || index2 == len2) return d[index1][index2] = 0;
  int &ret = d[index1][index2];
  if(ret != -1) return ret;
  if(x[index1] == y[index2]){
    ret = proc(index1+1, index2+1) + 1;
  }else{
    ret = 0;
    proc(index1, index2+1);
    proc(index1+1, index2);
  }
  return ret;
}

*/

int main(){

  memset(d,0,sizeof(d));
  cin>>x;
  cin>>y;
  len1 = x.length(); len2 = y.length();
  //proc(0,0);
  int ans = 0;

  /*
  for(int i = 0 ; i < len1; i++){
    for(int j = 0 ; j < len2; j++){

      ans = max(ans, d[i][j]);
    }
  }
  */

  for(int i = len1 -1; i >= 0; i--){
    for(int j = len2 -1; j >= 0 ; j--){
      if(x[i] == y[j]) d[i][j] = max(d[i][j], 1 + d[i+1][j+1]);
    }
  }
  for(int i = 0 ; i < len1; i++){
    for(int j = 0 ; j < len2; j++){
      ans = max(ans, d[i][j]);
    }
  }

  cout<<ans<<'\n';

  return 0;
}
