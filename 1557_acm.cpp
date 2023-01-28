#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mu[2000001], k;
vector<ll> ans;

ll function_(ll N){
  ll res = 0;
  for(ll i = 1LL; i*i <= N; i+=1LL){
    res += mu[i]*ll(N/(i*i));
  }
  return N-res;
}

int main(){

  cin>>k;
  mu[1] = 1LL;
  for(int i = 1LL; i <= 1000000LL; i+=1LL){
    for(int j = 2LL*i; j <= 1000000LL; j+=i){
      mu[j] -= mu[i];
    }
  }

  ll lo = 1LL, hi = 1000000000000LL;
  while(lo <= hi){
    ll mid = (lo+hi)>>1LL;
    if(function_(mid) >= k){
      ans.push_back(mid);
      hi = mid-1LL;
    }else{
      lo = mid+1LL;
    }
  }

  //cout<<ans.size()<<'\n';
  sort(ans.begin(),ans.end());
  cout<<ans[0]<<'\n';

  return 0;
}
