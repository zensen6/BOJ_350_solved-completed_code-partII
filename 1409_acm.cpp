#include<bits/stdc++.h>
using namespace std;

int n,x;
vector<int> arr;
int check[361];

int mod_minus(int x, int add){
  if(x-add < 0) return x-add+360;
  return x-add;
}
int mod_plus(int x, int add){
  return (x+add)%360;
}

int dfs(int here, int dist){
  check[here] = 1;
  int ret = 0;
  if(check[mod_minus(here, dist)] == 0){
    check[mod_minus(here, dist)] = 1;
    ret += dfs(mod_minus(here, dist), dist);
  }
  if(check[mod_plus(here, dist)] == 0){
    check[mod_plus(here, dist)] = 1;
    ret += dfs(mod_plus(here, dist), dist);
  }
  return ret+1;

}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  arr = vector<int>(n,0);
  for(int i = 0 ; i  <  n; i++){
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
  int ans=0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(j == n) j = 0;
      int c = 0;
      int dist = min(abs(arr[i]-arr[j]),360-abs(arr[i]-arr[j]));
      memset(check,-1,sizeof(check));
      for(int k = 0 ; k < n; k++){
        check[arr[k]] = 0;
      }
      for(int k = 0 ; k < n; k++){
        if(check[arr[k]] == 0){
          int r = dfs(arr[k],dist);
          c += ((r&1)?r-1:r);
        }
      }
      ans = max(ans,c);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
