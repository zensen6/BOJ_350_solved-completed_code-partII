#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tc,n;

int main(){

  cin>>tc;
  while(tc--){
    cin>>n;
    vector<ll> arr(n,0);
    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }
    ll A=0, B=0;
    sort(arr.begin(),arr.end());
    for(int i = n-1; i>= 0; i--){
      if(abs(i-(n-1)) == 0 || !(abs(i-(n-1))&1)){
        if(!(arr[i]&1)) A+=arr[i];
      }else{
        if(arr[i]&1) B+=arr[i];
      }
    }
    if(A>B) cout<<"Alice"<<'\n';
    else if(A==B) cout<<"Tie"<<'\n';
    else cout<<"Bob"<<'\n';
  }


  return 0;
}
