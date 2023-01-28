#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>

using namespace std;

int n,x;
vector<int> arr;
int d[201];

int dp(int index){

  int &ret = d[index];
  if(ret != -1) return ret;
  ret = 1;
  for(int i = index + 1; i < n; i++){
    if(arr[i] > arr[index]){
      ret = max(ret,1 + dp(i));
    }
  }
  return ret;
}

int main(){

  memset(d,-1,sizeof(d));
  cin>>n;
  for(int i = 0 ; i < n; i++){
    cin>>x;
    arr.push_back(x);
  }
  for(int i = 0 ; i < n; i++) {
    dp(i);
  }
  //
  int k = 0;
  for(int i = 0 ; i < n; i++){
    k = max(k,d[i]);
  }
  cout<<n-k<<'\n';


  return 0;
}
