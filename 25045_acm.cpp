#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,res=0;
vector<ll> A,B;
int main(){

  cin>>n>>m;
  A = vector<ll>(n,0);
  B = vector<ll>(m,0);
  for(int i=0;i<n;i++) cin>>A[i];
  for(int i=0;i<m;i++) cin>>B[i];
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  sort(B.begin(),B.end());
  int index=0;
  for(;index<min(A.size(),B.size());index++){
    if(A[index] < B[index]){
      break;
    }
  }
  index--;
  for(int i=0;i<=index;i++) res+=A[i];
  for(int i=0;i<=index;i++) res-=B[i];
  cout<<res<<'\n';
  return 0;
}
