#include<bits/stdc++.h>
using namespace std;

int n, d[1001];
vector<int> arr,ans;
bool isPrime[2001], check[1001];
vector<int> even, odd, p[1001];

bool dfs(int here){

  check[here] = true;
  for(int i = 0; i < p[here].size(); i++){
    int t = p[here][i];
    if(d[t] == 0 ||(!check[d[t]] && dfs(d[t]))){
      d[t] = here;
      d[here] = t;
      return true;
    }
  }
  return false;

}

int main(){

  bool iseven = true;
  memset(check,false,sizeof(check));
  for(int i = 2; i <= 2000; i++) isPrime[i] = true;
  for(int i = 2; i*i<=2000; i++){
    if(isPrime[i]){
      for(int j = i*i; j <= 2000; j+=i){
        isPrime[j] = false;
      }
    }
  }
  cin>>n;
  arr = vector<int>(n);
  for(int i = 0 ; i < n; i++) cin>>arr[i];
  for(int i = 0 ; i < n; i++){
    if(arr[i]&1) odd.push_back(arr[i]);
    else even.push_back(arr[i]);
  }
  if(arr[0] & 1) iseven = false;
  for(auto &e : even){
    for(auto &o : odd){
      if(isPrime[e+o]){
        if(iseven) p[e].push_back(o);
        else p[o].push_back(e);
      }
    }
  }
  if(even.size() != odd.size()){
    cout<<-1<<'\n';
    return 0;
  }else if(n == 2){
    if(isPrime[arr[0]+arr[1]]) cout<<arr[1]<<'\n';
    else cout<<-1<<'\n';
  }else{
    for(int i = 0 ; i < p[arr[0]].size(); i++){
      int match = 1;
      memset(d,0,sizeof(d));
      d[arr[0]] = p[arr[0]][i];
      d[p[arr[0]][i]] = arr[0];
      if(iseven){
        for(int j = 1; j < even.size(); j++){
          memset(check,false,sizeof(check));
          check[p[arr[0]][i]] = true;
          check[arr[0]] = true;
          if(dfs(even[j])) match++;
        }
        if(match == even.size()) ans.push_back(p[arr[0]][i]);
      }else{
        //for(int j = 1; j < odd.size(); j++){
          memset(check,false,sizeof(check));
          check[p[arr[0]][i]] = true;
          check[arr[0]] = true;
          if(dfs(odd[0])) match++;
        //}
        if(match == odd.size()) ans.push_back(p[arr[0]][i]);
        for(auto & o : odd){
          cout<<o<<": "<<d[o];
          cout<<'\n';
        }
      }
    }
    if(!ans.size()){
      cout<<-1<<'\n';
    }else{

      sort(ans.begin(),ans.end());
      //for(auto &k: ans) cout<<k<<" ";
      cout<<'\n';
    }
  }


  return 0;

}
