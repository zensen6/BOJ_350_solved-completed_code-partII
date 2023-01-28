#include<bits/stdc++.h>
using namespace std;

int t,n,d,k;
vector<int> v;
vector<pair<int,int>> dp;
int d_[1000001][11];

int proc(int index, int k_){

  int& ret = d_[index][k_];
  if(k_ == 0 || index >= n) return ret = 0;
  if(ret != -1) return ret;
  ret = 0;
  ret = dp[index].first + proc(index + dp[index].first, k_ -1);
  //ret = max(ret, proc(index+1, k_));
  int next = index;
  while(next+1 != n && v[next] == v[next+1]) next++;
  ret = max(ret, proc(next+1, k_));
  return ret;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t>>n>>d>>k;
  v = vector<int>(n,0);
  dp = vector<pair<int,int>>(n,{0,0});
  memset(d_,-1, sizeof(d_));
  for(int i = 0 ; i < n; i++){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  int pivot = 0, r = 1;
  while(r < n){
    if(pivot > 0 && v[pivot] == v[pivot-1]){
      dp[pivot] = {dp[pivot-1].first,pivot};
      pivot++;
    }
    else {
      if(v[r] <= v[pivot] + d - 1){
        r++;
      }else{
        dp[pivot] = {r - pivot,pivot};
        pivot++;
      }
    }
  }
  while(pivot < n){
    dp[pivot] = {n - pivot,pivot};
    pivot++;
  }

  cout<<proc(0,k)<<'\n';

  return 0;
}
