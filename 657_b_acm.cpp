#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  ll l,r,m;

  cin>>tc;
  while(tc--){
    cin>>l>>r>>m;
    if(m <= l){
      cout<<l<<" "<<l<<" "<<l+l-m<<'\n';
    }else if(m >= r){

      for(ll k = l; k <= r; k++){
        if(m - (ll(m)/k)*k <= r - l){
          cout<<k<<" "<<r<<" "<<r - m + (ll(m)/k)*k<<'\n';
          break;
        }
        if(m - ((ll(m)/k)+1)*k >= l - r){
          cout<<k<<" "<<l<<" "<<l - m + ((ll(m)/k)+1)*k<<'\n';
          break;
        }

      }

    }
    else{
      cout<<l<<" "<<r<<" "<<r-m+ll(ll(m)/l)*l<<'\n';
    }
  }


  return 0;
}
