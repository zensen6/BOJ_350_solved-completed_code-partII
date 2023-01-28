#include<bits/stdc++.h>
using namespace std;

int tc,x;

int main(){

  cin>>tc;
  while(tc--){
    cin>>x;
    if(x&1){
      if((x>>1)&1){
        cout<<(x>>1)-2<<" "<<(x>>1)+2<<" ";
      }else{
        cout<<(x>>1)-1<<" "<<(x>>1)+1<<" ";
      }
    }else{
      cout<<(x>>1)<<" "<<(x>>1)-1<<" ";
    }
    cout<<1<<'\n';

  }



  return 0;
}
