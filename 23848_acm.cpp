#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
ll N;

int main(){
  scanf("%llu",&N);
  bool done = false;
  for(ll r = 2; r<=1000000; r++){
    ll s_= r*r + r + 1;
    for(ll k = 4; k <= 40; k++){
      if(s_ > N) break;
      if(N % s_ == 0){
        done = true;
        printf("%llu\n",k-1);
        for(int iter = 1; iter <= k-1; iter++){
          printf("%llu ",(N/s_)*(ll)pow<ll>(r,iter-1));
        }
        return 0;
      }
      s_ *= r;
      s_ += 1;
    }
  }
  if(!done) printf("%d\n",-1);

  return 0;
}
