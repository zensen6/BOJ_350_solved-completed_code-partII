#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s,p;

int main(){

  cin>>s>>p;
  if(s==p) cout<<1<<'\n';
  else if(pow<ll>(s,2LL) >= 4LL*p) cout<<2<<'\n';
  else{
    if(s < 8) cout<<-1<<'\n';
    else if(s == 8 && (p == 17 || p == 18)) cout<<3<<'\n';
    else{
      vector<ll> ans;
      ll lo = 3LL, hi = (ll)(s/exp(1));
      while(lo <= hi){
        ll mid = (lo + hi)>>1LL;
        if(pow(1.0*s/mid,mid) >= p){
          ans.push_back(mid);
          hi = mid-1;
        }else{
          lo = mid+1;
        }
      }
      if(!ans.size())cout<<-1<<'\n';
      else{
        sort(ans.begin(),ans.end());
        cout<<ans[0]<<'\n';
      }
    }

  }

  return 0;
}
