#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
int n,x;
ll ans=0;
vector<int> arr;

int main(){

  cin>>n;
  arr = vector<int>(2000001,0);
  for(int i=0;i<n;i++){
    cin>>x;
    arr[x]++;
  }
  for(int i=1;i<=2000000;i++){
    ll res = 0;
    for(int j=i;j<=2000000;j+=i){
      res += arr[j];
    }
    ans = max<ll>(res>=2? res*i:0,ans);
  }
  cout<<ans<<'\n';
  return 0;
}
