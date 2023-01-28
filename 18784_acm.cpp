#include<bits/stdc++.h>
#define MOD 1000000007LL
#define f first
#define s second
using namespace std;

typedef long long ll;
int n,x,y;
ll ans = 0,dx[100001], dy[100001];

vector<pair<pair<int,int>,int>> v, k;

bool compY(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
  if(a.f.s == b.f.s) return a.f.f < b.f.f;
  return a.f.s < b.f.s;
}
bool compX(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
  if(a.f.f == b.f.f) return a.f.s < b.f.s;
  return a.f.f < b.f.f;
}
int main(){

  memset(dx,0,sizeof(dx));
  memset(dy,0,sizeof(dy));
  cin>>n;
  for(int i = 0 ; i < n; i++){
    cin>>x>>y;
    v.push_back({{x,y},i});
    k.push_back({{x,y},i});
  }

  sort(v.begin(), v.end(), compY);
  sort(k.begin(), k.end(), compX);
  int j=-1, start = 0;
  for(int i = 0 ; i < n; i++){
    if(i > j){
      start = i;
      j = i+1;
      ll dxs = 0;
      while(v[j].f.s == v[i].f.s){
        dxs += (v[j].f.f - v[i].f.f);
        j++;
      }
      j--;
      dx[v[i].s] = dxs;
    }else{
      dx[v[i].s] += dx[v[i-1].s];
      dx[v[i].s] += (i-start)*(v[i].f.f - v[i-1].f.f);
      dx[v[i].s] -= (j-i+1)*(v[i].f.f - v[i-1].f.f);
    }
  }
  // dy구하는 것도 동일한 방법
  /*
  for(int i = 0; i  < n; i++){
    cout<<dx[i]<<" ";
  }
  cout<<'\n';
  */

  j=-1, start = 0;
  for(int i = 0 ; i < n; i++){
    if(i > j){
      start = i;
      j = i+1;
      ll dys = 0;
      while(k[j].f.f == k[i].f.f){
        dys += (k[j].f.s - k[i].f.s);
        j++;
      }
      j--;
      dy[k[i].s] = dys;
    }else{
      dy[k[i].s] += dy[k[i-1].s];
      dy[k[i].s] += (i-start)*(k[i].f.s - k[i-1].f.s);
      dy[k[i].s] -= (j-i+1)*(k[i].f.s - k[i-1].f.s);
    }
  }
  /*
  for(int i = 0; i < n; i++){
    cout<<dy[i]<<" ";
  }
  */

  for(int i = 0 ; i < n; i++){
    ans += dx[i]*dy[i];
    ans %= MOD;
  }
  cout<<ans<<'\n';

  return 0;
}
