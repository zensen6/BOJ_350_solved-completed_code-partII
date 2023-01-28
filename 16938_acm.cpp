#include<bits/stdc++.h>
using namespace std;

int n,l,r,x,k, ans=0;
vector<int> arr;

void proc(int index, int chose, int sum, int least, int maximum){
  if(index >= n){
    if(maximum - least >= x && sum >= l && sum <= r && chose >= 2)
      ans += 1;
    return;
  }
  if(least == -1){
    proc(index + 1, chose + 1, arr[index], arr[index],arr[index]);
    proc(index + 1, chose, 0, -1,-1);
  }else{
    proc(index + 1, chose + 1, sum + arr[index], least, arr[index]);
    proc(index + 1, chose, sum, least, maximum);
  }

}

int main(){

  cin>>n>>l>>r>>x;
  for(int i = 0 ; i < n; i++){
    cin>>k;
    arr.push_back(k);
  }
  sort(arr.begin(),arr.end());
  proc(0,0,0,-1,-1);
  cout<<ans<<'\n';
  return 0;
}
