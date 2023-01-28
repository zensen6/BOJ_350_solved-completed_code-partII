#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,k;

int main(){

  cin>>n>>k;
  ll L = ll((1440*n-660-k)/(1440+k));
  ll a = 660+k+(1440+k)*L;
  if(a+18*60>=1440*n){
    cout<<3<<'\n';
    ll res = a+18*60-1440*n;
    ll hour = res/60, minute = res - (res/60)*60;
    /*
    if(to_string(hour) == 1) cout<<"0"<<hour<<":";
    else cout<<hour<<":";
    if(to_string(minute) == 1) cout<<"0"<<minute<<'\n';
    else cout<<minute<<'\n';
    */
  }else if(a+21*60>=1440*n){
    cout<<2<<'\n';
    ll res = a+21*60-1440*n;
    ll hour = res/60, minute = res - (res/60)*60;

  }else if(a+24*60>=1440*n){
    cout<<1<<'\n';
    ll res = a+24*60-1440*n;
    ll hour = res/60, minute = res - (res/60)*60;

  }else cout<<0<<'\n';

  return 0;
}
