#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d[52][100001], n,t,m,p,r;
vector<int> arr;
vector<ll> M,P,R;

ll go(int index, ll rest){
  ll &ret=d[index][rest];
  if(ret != -1LL) return ret;
  if(index == n) return ret=0;
  ret = 0;
  if(rest-R[arr[index]] >= 0){
    if(M[arr[index]]-(t-rest+R[arr[index]])*P[arr[index]] >= 0)
      ret = max<ll>(ret, M[arr[index]]-(t-rest+R[arr[index]])*P[arr[index]] + go(index+1,rest-R[arr[index]]));
  }
  ret = max<ll>(ret,go(index+1, rest));
  return ret;
}

bool comp(int &a, int &b){
  return P[a]*R[b]*1LL > P[b]*R[a]*1LL;
}


int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(d,-1LL,sizeof(d));
  cin>>n>>t;
  for(int i=0;i<n;i++) arr.push_back(i);
  for(int j=0;j<n;j++){
    cin>>m;
    M.push_back(m);
  }
  for(int j=0;j<n;j++){
    cin>>p;
    P.push_back(p);
  }
  for(int j=0;j<n;j++){
    cin>>r;
    R.push_back(r);
  }
  if(arr.size()>1) sort(arr.begin(),arr.end(),comp);
  //
  cout<<go(0,t)<<'\n';

    return 0;
}
