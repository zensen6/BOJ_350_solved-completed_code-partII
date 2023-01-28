#include<bits/stdc++.h>
using namespace std;

int d[1000][1000];
vector<int> arr;

int proc(int left, int right){
  int &ret = d[left][right];
  if(left > right){
    return ret = 0;
  }
  if(ret != -1) return ret;
  ret = max(arr[left] - proc(left+1,right), arr[right] - proc(left,right-1));
  return ret;
}


int main(){

  int tc,n,x;
  cin>>tc;
  while(tc--){
    memset(d,-1,sizeof(d));
    cin>>n;
    arr = vector<int>(n,0);
    int s = 0;
    for(int i = 0 ; i < n; i++){
      cin>>arr[i];
      s+=arr[i];
    }
    int surplus = proc(0,n-1);
    cout<<(s-surplus)/2+surplus<<'\n';
  }

  return 0;
}
