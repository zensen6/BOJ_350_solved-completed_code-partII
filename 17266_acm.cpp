#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> pos;
bool check[100002];

int main(){

  cin>>n;
  cin>>m;
  pos = vector<int>(m,0);
  int ans = 0;
  for(int i = 0; i < m; i++){
    cin>>pos[i];
  }

  if(m == 1){
    cout<<max(pos[0],n-pos[0])<<'\n';
    return 0;
  }
  for(int i = 0 ; i < m-1; i++){
    if(i == 0){
      ans = max(ans, pos[i]);
    }else{
      ans = max(ans,(pos[i+1]-pos[i]+1)/2);
    }
  }
  ans = max(ans,n-pos[m-1]);
  cout<<ans<<'\n';
  return 0;
}
