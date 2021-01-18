#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  string x;
  cin>>n>>k;
  cin>>x;
  int i=0,c=0;
  if(n==1){
    if(k>=1)cout<<0<<'\n';
    else cout<<x<<'\n';
  }else{
    while(i < n && c<k){
      if(i==0){
        if(x[i]=='1'){
          i++;
          continue;
        }
        else{
          x[i] = '1';
          c++;
        }
      }else{
        if(x[i]=='0'){
          i++;
          continue;
        }
        else{
          x[i] = '0';
          c++;
        }
      }
      i++;
    }
    cout<<x<<'\n';
  }



  return 0;
}
