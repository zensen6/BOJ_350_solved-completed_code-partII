#include<bits/stdc++.h>
#define MIN -1000000000000000000LL
using namespace std;

typedef long long ll;
ll arr[19][19];
ll k[1<<18],d[19][1<<18],C[19],R[19];
int n;

int main(){

  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
      R[i] += arr[i][j];
    }
  }
  for(int j=0;j<n;j++){
    for(int i=0;i<n;i++){
      C[j] += arr[i][j];
    }
  }
  for(int state=0;state<(1<<n);state++){
    for(int col=0;col<n;col++){
      for(int i=0;i<n;i++){
        if((1<<i)&state) d[col][state] += arr[i][col];
      }
    }
  }
  for(int state=0;state<(1<<n);state++){
    for(int col=0;col<n;col++){
      if(d[col][state] > C[col]-d[col][state]){
        k[state] += C[col]-d[col][state];
      }else k[state] += d[col][state];
    }
  }
  ll ans=MIN;
  for(int state=0;state<(1<<n);state++){
    ans = max<ll>(ans,k[state]);
  }
  cout<<ans<<'\n';
  return 0;
}
