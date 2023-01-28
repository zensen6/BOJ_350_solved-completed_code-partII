#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll ans = 0;
vector<int> arr,neg;
vector<int> pos;

int main(){

  cin>>n;
  arr = vector<int> (n,0);
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i] > 0){
      pos.push_back(i);
    }else if(arr[i] < 0){
      neg.push_back(i);
    }
  }
  int p = 0, nn = 0;
  int s = pos.size();
  while(p < s){
    if(abs(arr[pos[p]]) > abs(arr[neg[nn]])){
      arr[pos[p]] -= abs(arr[neg[nn]]);
      ans += ll(abs(pos[p]-neg[nn]))*ll(abs(arr[neg[nn]]));
      arr[neg[nn]] = 0;
      nn++;
    }else if(abs(arr[pos[p]]) < abs(arr[neg[nn]])){
      ans += ll(abs(pos[p]-neg[nn]))*ll(abs(arr[pos[p]]));
      arr[neg[nn]] += abs(arr[pos[p]]);
      arr[pos[p]] = 0;
      p++;
    }else{
      ans += ll(abs(pos[p]-neg[nn]))*ll(abs(arr[neg[nn]]));
      arr[pos[p]] = 0;
      arr[neg[nn]] = 0;
      p++;
      nn++;
    }
  }


  cout<<ans<<'\n';
  return 0;
}
