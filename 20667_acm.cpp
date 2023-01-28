#include<bits/stdc++.h>
#define  MAX 10000
using namespace std;

int n,m,k,x,y,z, d[101][1001];
vector<pair<pair<int,int>,int>> arr;

int dp(int index, int cpu){
  if(cpu >= m && )
  int &ret = d[index][cpu];
  if(ret != MAX) return ret;
  ret = 0;

  
}

int main(){

  for(int i = 0 ; i < 101; i++){
    for(int j = 0 ; j < 1001; j++){
      d[i][j] = MAX;
    }
  }
  cin>>n>>m>>k;
  for(int i = 0 ; i < n; i++){
    cin>>x>>y>>z;
    arr.push_back({{x,y},z});
  }



  return 0;
}
