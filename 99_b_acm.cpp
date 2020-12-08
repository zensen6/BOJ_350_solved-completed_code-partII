#include<bits/stdc++.h>
using namespace std;

int t,x;
int main(){

  cin>>t;
  while(t--){
    cin>>x;
    for(int k = 1; k < 2000; k++){
      if(k*(k-1)/2 < x && k*(k+1)/2 >= x){
        if(x == -1 + k*(k+1)/2) cout<< k + 1<<'\n';
        else cout<<k<<'\n';
        break;
      }
    }

  }

  return 0;
}
