#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;
vector<int> vx,vy;

int main(){

  cin>>n>>m;
  for(int i = 0 ; i < m; i++){
    cin>>x>>y;
    vx.push_back(x);
    vy.push_back(y);
  }
  sort(vx.begin(),vx.end());
  sort(vy.begin(),vy.end());
  int pivotx = vx[vx.size()/2], pivoty = vy[vy.size()/2];
  int dx=0,dy=0;
  for(int i = 0; i < m; i++){
    dx += abs(pivotx-vx[i]);
    dy += abs(pivoty-vy[i]);
  }
  cout<<dx+dy<<'\n';
  return 0;
}
