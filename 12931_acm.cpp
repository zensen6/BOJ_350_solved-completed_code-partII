#include<bits/stdc++.h>
using namespace std;
vector<int> A,B;
int n;

int main(){

  int zero=0;
  cin>>n;
  A=vector<int>(n,0);
  B=vector<int>(n,0);
  for(int i=0;i<n;i++){
    cin>>B[i];
    if(!B[i]) zero++;
  }
  int ans=0;
  while(1){
    for(int i=0;i<n;i++){
      if(B[i]==1){
        B[i]=0;
        ans++;
      }
    }
    zero=0;
    for(int i=0;i<n;i++) if(!B[i]) zero++;
    if(zero==n) break;
    int one=0;
    while(!one){
      one=0;
      for(int i=0;i<n;i++){
        if(B[i]&1 && B[i]!=1){
          ans++;
          B[i]>>=1;
        }
        else B[i]>>=1;
        if(B[i]==1)one++;
      }
      ans++;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
