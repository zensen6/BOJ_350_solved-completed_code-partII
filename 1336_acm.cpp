#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;

ll dp[500][100001];
ll n,k,d;

int main(){

  cin>>n>>k>>d;
  ll ans = 0;
  memset(dp,0,sizeof(dp));
  for(int i = 0; i <= d-1; i++) dp[1][i] = 1LL;
  for(int i = 2; i <= k-1; i++) dp[i][0] = 1LL;

  for(int i = 2; i<=k-1; i++){
    for(int a1 = 1; a1<=d; a1++){
      ll R = n - a1*k;
      if(R - ((i+1)*i)/2 < 0) break;
      for(int l = 0 ; l <= d-1; l++){
        if(R - ((i+1)*i)/2 - l*i < 0) break;
        if(!dp[i][R-((i+1)*i)/2]) dp[i][R-((i+1)*i)/2] += dp[i-1][R-((i+1)*i)/2 -l*i];
        dp[i][R-((i+1)*i)/2] %= MOD;
      }
    }
  }
  for(int a1 = 1; a1 <= d; a1++){
    if(n-k*a1-k*(k-1)/2 < 0) break;
    ans += dp[k-1][n-k*a1-k*(k-1)/2];
    ans %= MOD;
  }
  cout<<dp[2][3]<<" "<<dp[2][0]<<'\n';
  cout<<ans<<'\n';

  return 0;
}
