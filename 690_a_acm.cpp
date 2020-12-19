#include<bits/stdc++.h>
using namespace std;

int t,n,x;

int main(){

  cin>>t;
  while(t--){
    cin>>n;
    vector<int> v(n+1,0), ans(n+1,0);
    for(int i = 1; i <= n; i++){
      cin>>v[i];
    }
    for(int i = 1; i <= (n+1)/2; i++){
      ans[i*2-1] = v[i];
    }
    for(int i = n; i>=(n+1)/2 + 1; i--){
      ans[2*(n+1-i)] = v[i];

    }
    for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';
    cout<<'\n';
  }



  return 0;
}
