#include<bits/stdc++.h>
using namespace std;

int tc,n,D[3001];
string x;


int main(){

  cin>>tc;
  while(tc--){
    int ans=0;
    memset(D,0,sizeof(D));
    cin>>n;
    cin>>x;
    for(int i=1;i<=n;i++){
      D[i] = D[i-1] + (x[i-1]=='+'? 1:-1);
    }
    for(int r=1;r<=n;r++){
      for(int l=1;l<=r;l++){
        if(D[r]-D[l-1]==0 || D[r]-D[l-1]==-3) ans++;
      }
    }
    cout<<ans<<'\n';
  }


  return 0;
}
