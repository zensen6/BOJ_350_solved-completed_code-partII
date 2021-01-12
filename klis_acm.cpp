#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MAX = numeric_limits<int>::max();
ll tc,n,k, d[502], c[502];
vector<ll> arr;
vector<ll> ans;

ll lis(int start){
  ll& ret = d[start+1];
  if(ret != -1) return ret;
  ret = 1;
  for(int next = start + 1; next < n; next++){
    if(start == -1){
      ret = max<ll>(ret, lis(next) + 1);
    }else if(arr[next] > arr[start]){
      ret = max<ll>(ret, lis(next) + 1);
    }
  }
  return ret;
}

ll count(int start){
  ll &ret = c[start];
  if(ret != -1) return ret;
  ret = 0;
  bool sole = true;
  for(int next = start+1; next < n; next++){
    if(lis(next) + 1 == lis(start) && arr[next] > arr[start]){
      ret = min<ll>(MAX, ret + count(next));
      sole = false;
    }
  }
  if(sole) ret = 1;
  return ret;
}

void solve(int start){
  vector<pair<int,int>> save;
  for(int next = start+1; next<n;next++){
    if(lis(next) == lis(start) - 1){
      if(start == -1){
        save.push_back({arr[next],next});
      }
      else if(arr[next]>arr[start])
        save.push_back({arr[next],next});
    }
  }
  sort(save.begin(),save.end());
  for(auto &p: save){
    if(k > count(p.second)){
      k -= count(p.second);
    }
    else{
      ans.push_back(p.first);
      solve(p.second);
      break;
    }
  }

}

int main(){

  cin>>tc;
  while(tc--){
    ans.clear();
    memset(d,-1,sizeof(d));
    memset(c,-1,sizeof(c));
    cin>>n>>k;
    arr = vector<ll> (n,0);
    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }
    lis(-1);

/*
    for(int i = 0; i < n; i++){
      cout<<lis(i)<<" ";
    }
*/


    for(int i = 0 ; i < n; i++){
      if(c[i] == -1) count(i);
    }

    /*
    cout<<"\n";
    for(int i = 0; i < n; i++){
      cout<<count(i)<<' ';
    }
    cout<<'\n';
*/

    solve(-1);
    cout<<ans.size()<<'\n';
    for(auto &p: ans) cout<<p<<" ";
    cout<<'\n';

  }



  return 0;
}
