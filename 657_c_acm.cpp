#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

  int tc;
  ll n, m, x, y;
  scanf("%d",&tc);
  while(tc--){
    scanf("%lld %lld",&n,&m);
    vector<ll> b[m+1], vector<ll> a[m+1];
    for(int i = 1; i<= m; i++){
      scanf("%lld %lld", &x, &y);
      a[i].push_back(x);
      b[i].push_back(y);
    }




    getchar();
  }




  return 0;
}
