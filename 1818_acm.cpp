#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr,lis;

int main(){

  cin>>n;
  arr = vector<int>(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  for(int i=0;i<n;i++){
    if(!lis.size()) lis.push_back(arr[i]);
    else if(lis.back() > arr[i]){
      int idx = lower_bound(lis.begin(),lis.end(),arr[i]) - lis.begin();
      lis[idx] = arr[i];
    }else lis.push_back(arr[i]);
  }
  cout<<n-lis.size()<<'\n';

  return 0;
}
