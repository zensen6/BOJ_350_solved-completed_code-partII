#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){

  int tc;
  ll n,k;
  cin>>tc;
  while(tc--){

    cin>>n>>k;
    ll sum_ = 10000*(n/10000)*k;
    for(int i = 0 ; i <= n%10000; i++){
      sum_ = max<ll>(sum_, 10000*(n/10000)*k + 10000*((i*k)/10000) + (k*(n%10000 - i)*9)/10);
    }
    cout<<sum_<<'\n';

  }


  return 0;
}
