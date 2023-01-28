#include<bits/stdc++.h>
#define MAX 1000000001
#define x first
#define y second
using namespace std;

bool comp(pair<pair<int,int>,pair<int,int>> &a,pair<pair<int,int>,pair<int,int>> &b){
  if((a.x.x - a.y.x)*b.x.y == (b.x.x - b.y.x)*a.x.y) return a.y.y < b.y.y;
  return (a.x.x - a.y.x)*b.x.y > (b.x.x - b.y.x)*a.x.y;
}

int main(){

  int n;
  cin>>n;
  vector<int> arr(n,0), sum(n,0), mini(n,0), ans;
  for(int i = 0 ; i < n; i++){
    cin>>arr[i];
  }
  sum[n-1] = arr[n-1];
  mini[n-1] = arr[n-1];
  for(int i = n-2; i>=0; i--){
    sum[i] = sum[i+1] + arr[i];
    mini[i] = min(mini[i+1], arr[i]);
  }
  vector<pair<pair<int,int>,pair<int,int>>> pk;
  for(int k = 1 ; k < n-1; k++){
    pk.push_back({{sum[k],n-k-1},{mini[k],k}});
  }
  sort(pk.begin(),pk.end(),comp);
  ans.push_back(pk[0].y.y);
  for(int i = 0 ; i < pk.size()-1; i++){
    if((pk[i].x.x - pk[i].y.x)*pk[i+1].x.y == (pk[i+1].x.x - pk[i+1].y.x)*pk[i].x.y){
      ans.push_back(pk[i+1].y.y);
    }
    else break;
  }

  sort(ans.begin(),ans.end());
  for(auto &p: ans){
    cout<<p<<'\n';
  }

  return 0;
}
