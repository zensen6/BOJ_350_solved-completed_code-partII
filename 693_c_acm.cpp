#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tc,n,x;

int main(){

  cin>>tc;
  while(tc--){
    cin>>n;
    vector<ll> arr(n+1,0);
    for(int i = 1; i <= n; i++){
      cin>>arr[i];
    }
    vector<ll> d(n+1,0);
    d[n] = arr[n];
    for(int i = n-1; i >= 1; i--){
      if(arr[i] + i <= n){
        d[i] = d[i+arr[i]] + arr[i];
      }else{
        d[i] = arr[i];
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
      ans = max<ll>(ans, d[i]);
    }
    cout<<ans<<'\n';
  }



  return 0;
}
