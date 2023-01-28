#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll xs,ys,xe,ye,x_1,y_1,x_2,y_2;
vector<pair<pair<ll,ll>,pair<ll,ll>>> pos;
ll ans=2000000000LL;
vector<int> index_{0,1,2};

ll distance_(pair<ll,ll> a, pair<ll,ll> b){
  return ll(abs(a.first-b.first))+ll(abs(a.second-b.second));
}

void proc(int ind, pair<ll,ll> cur, ll dist){
  if(ind==3){
    ans=min<ll>(ans,dist+distance_(cur,{xe,ye}));
    return;
  }
  ll x_1=pos[index_[ind]].first.first,y_1=pos[index_[ind]].first.second,x_2=pos[index_[ind]].second.first,y_2=pos[index_[ind]].second.second;
  proc(ind+1,cur,dist);
  proc(ind+1,{x_2,y_2},dist+distance_(cur,{x_1,y_1})+10);
  proc(ind+1,{x_1,y_1},dist+distance_(cur,{x_2,y_2})+10);
  return;
}

int main(){

  cin>>xs>>ys;
  cin>>xe>>ye;
  for(int i=0;i<3;i++){
    cin>>x_1>>y_1>>x_2>>y_2;
    pos.push_back({{x_1,y_1},{x_2,y_2}});
  }

  do{
    proc(0,{xs,ys},0);
    //for(auto&p:index_) cout<<p<<" ";
    //cout<<'\n';
  }while(next_permutation(index_.begin(),index_.end()));
  cout<<ans<<'\n';

  return 0;
}
