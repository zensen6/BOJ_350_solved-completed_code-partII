#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

  int n;
  cin>>n;
  vector<ll>arr(n,0);
  for(int i = 0 ; i < n; i++){
    cin>>arr[i];
  }
  int a,b,c;
  ll ans = 3000000001LL;
  sort(arr.begin(),arr.end());
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int k = lower_bound(arr.begin(),arr.end(),-(arr[i]+arr[j])) - arr.begin();
      if(k-1 >= 0 && k-1 != i && k-1 != j){
        if(abs<ll>(arr[i]+arr[j]+arr[k-1]) < ans){
          a=i,b=j,c=k-1;
          ans = abs<ll>(arr[i]+arr[j]+arr[k-1]);
        }
      }
      if(k != n && k!=i && k!=j){
        if(abs<ll>(arr[i]+arr[j]+arr[k]) < ans){
          a=i,b=j,c=k;
          ans = abs<ll>(arr[i]+arr[j]+arr[k]);
        }
      }
    }
  }
  vector<int> v;
  v.push_back(arr[a]); v.push_back(arr[b]); v.push_back(arr[c]);
  sort(v.begin(),v.end());
  for(auto p:v){
    cout<<p<<" ";
  }
  cout<<'\n';
  return 0;
}
