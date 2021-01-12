#include<bits/stdc++.h>
#define MAX 100000000001LL
using namespace std;

typedef long long ll;
ll n,m,sum=0;
vector<ll> C,M;

ll d[10001];


int main(){

  memset(d,0,sizeof(d));

  cin>>n>>m;
  M = vector<ll>(n,0),C = vector<ll>(n,0);
  for(int i = 0 ; i < n; i++){
    cin>>M[i];
  }
  for(int  i = 0 ; i < n; i++){
    cin>>C[i];
    sum+=C[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = sum; j >= C[i]; j--){
      d[j] = max(d[j], d[j-C[i]]+M[i]);
    }
  }
  for(int i = 0 ; i <= sum; i++){
    if(d[i] >= m){
      cout<<i<<'\n';
      return 0;
    }
  }

  return 0;
}
