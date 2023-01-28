#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;
ll n;
ll gcd(ll a, ll b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a*b/gcd(a,b);
}
int main(){

  cin>>t;
  while(t--){
    cin>>n;
    if(n == 6) {
      cout<<1<<" "<<3<<" "<<1<<" "<<1<<'\n';
    }else{
      if(n == 7){
        cout<<2<<" "<<2<<" "<<2<<" "<<1<<'\n';
      }
      else if(n % 4 == 0){
        cout<<(n/4)<<" "<<(n/4)<<" "<<(n/4)<<" "<<(n/4)<<'\n';
      }else if(n%4 == 1){
        cout<<(n/4)<<" "<<(n/2)<<" "<<(n/4)<<" "<<1<<'\n';
      }else if(n%4 == 2){
        cout<<((n-2)/2)+1<<" "<<((n-2)/2)-1<<" "<<1<<" "<<1<<'\n';
      }else{
        cout<<(n/4)*2<<" "<<(n/4)*2+1<<" "<<1<<" "<<1<<'\n';
      }
    }

  }



  return 0;
}
