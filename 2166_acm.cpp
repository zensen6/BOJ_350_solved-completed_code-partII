#include<bits/stdc++.h>
using namespace std;

int n,x,y;
typedef long long ll;
vector<pair<ll,ll>> pos;

ll cross(ll x1, ll y1, ll x2, ll y2){
  return (ll)(x1*y2)-(ll)(x2*y1);
}

int main(){

  cin>>n;
  pos = vector<pair<ll,ll>>(n);
  for(int i=0;i<n;i++){
    cin>>pos[i].first>>pos[i].second;
  }
  double ans = 0;
  for(int i=1;i<n-1;i++){
    ans += (cross(pos[i].first-pos[0].first,pos[i].second-pos[0].second,pos[i+1].first-pos[0].first,pos[i+1].second-pos[0].second))/(double)2;
  }
  cout<<fixed;
  cout.precision(1);
  cout<<abs(ans)<<'\n';

  return 0;
}
