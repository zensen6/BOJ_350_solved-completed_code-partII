#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tc,n,m, d[103][103];
vector<ll> A, B;
ll neg = numeric_limits<ll>::min();

ll dp(int a, int b){

  ll &ret = d[a+1][b+1];
  if(ret != -1) return ret;
  ret = 0;
  ll curmax;
  if(a==-1){
    curmax = (b==-1 ? neg: B[b]);
  }else{
    curmax = (b==-1 ? A[a] : max<ll>(A[a],B[b]));
  }
  for(int indexA = a+1; indexA < n; indexA++){
    if(curmax < A[indexA]){
      ret = max<ll>(ret, dp(indexA, b)+1);
    }
  }
  for(int indexB = b+1; indexB < m; indexB++){
    if(curmax < B[indexB]){
      ret = max<ll>(ret, dp(a, indexB)+1);
    }
  }

  return ret;
}


int main(){

    cin>>tc;
    while(tc--){
      memset(d,-1,sizeof(d));
      cin>>n>>m;
      A = vector<ll>(n,0), B = vector<ll>(m,0);
      for(int i= 0 ; i < n; i++){
        cin>>A[i];
      }
      for(int i = 0 ; i < m; i++){
        cin>>B[i];
      }
      cout<<dp(-1,-1)<<'\n';

    }


  return 0;
}
