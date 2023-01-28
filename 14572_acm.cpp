#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,k,D,M,d,x;
vector<pair<ll,ll>> v;

bool comp(pair<ll,ll>&a, pair<ll,ll>&b){
  return a.first>b.first;
}

ll effi(ll UNION, ll CROSS, int size){
  return (__builtin_popcount(UNION)-__builtin_popcount(CROSS))*size;
}

vector<ll> algorithm_[31];

int main(){

  cin>>n>>k>>D;
  for(int i=0;i<n;i++){
    cin>>M>>d;
    ll bitmask = 0;
    for(int j=0;j<M;j++){
      cin>>x;
      bitmask|=(1LL<<x);
    }
    v.push_back({d,bitmask});
  }
  sort(v.begin(),v.end(),comp);

  for(int i=1;i<31;i++){
    for(int j=0;j<n;j++){
      int mask=v[j].second;
      if((1LL<<i)&mask)algorithm_[i].push_back(j+1);
    }
  }
  for(int i=1;i<31;i++){
    sort(algorithm_[i].begin(),algorithm_[i].end());
  }
  int l=0,r=1;
  ll ans=0,dist;
  vector<pair<int,int>> candi;
  while(l<=r && r<n){
    dist=v[l].first-v[r].first;
    if(dist>D){
      l++;
      if(l==r)r++;
    }else{
      candi.push_back({l+1,r+1});
      r++;
    }
  }


  for(auto &p:candi){
    int l=p.first,r=p.second;
    ll UNION=0, CROSS=0;
    for(int num=1;num<=k;num++){
      int l1=lower_bound(algorithm_[num].begin(),algorithm_[num].end(),l)-algorithm_[num].begin();
      int r1=lower_bound(algorithm_[num].begin(),algorithm_[num].end(),r)-algorithm_[num].begin();
      if(l1!=algorithm_[num].size()&&algorithm_[num][l1]<=r) UNION|=(1LL<<num);
      if(algorithm_[num][l1]==l&&algorithm_[num][r1]==r&&r1-l1+1==r-l+1){
        CROSS|=(1LL<<num);
      }
    }
    ans=max(ans,effi(UNION,CROSS,r-l+1));
  }
  cout<<ans<<'\n';
  return 0;
}
