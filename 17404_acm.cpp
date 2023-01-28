#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

vector<vector<int>> arr;

int d[1001][3][3];
int n;

int proc(int index, int prev, int zero){

  int &ret = d[index][prev][zero];
  if(index==n-1){
    ret = MAX;
    for(int i = 0; i < 3; i++){
      if(i != prev && i != zero){

        ret = min(ret, arr[n-1][i]);
      }
    }
    return ret;
  }
  if(ret != MAX) return ret;
  else{
      ret = min(proc(index+1,(prev+1)%3,zero)+arr[index][(prev+1)%3],proc(index+1,(prev+2)%3,zero)+arr[index][(prev+2)%3]);
  }
  return ret;
}

int main(){

  for(int i = 0 ; i < 1001; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0 ; k < 3; k++){
        d[i][j][k] = MAX;
      }
    }
  }
  cin>>n;
  arr = vector<vector<int>>(n,vector<int>(3,0));
  for(int i = 0 ; i < n; i++){
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
  }
  cout<<min(min(proc(1,0,0)+arr[0][0],proc(1,1,1)+arr[0][1]),proc(1,2,2)+arr[0][2])<<'\n';

  return 0;
}
