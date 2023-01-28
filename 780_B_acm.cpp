#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int tc;
int n;

int main(){

  cin>>tc;
  while(tc--){
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    if(n==1){
      if(arr[0] > 1) cout<<"NO"<<'\n';
      else cout<<"YES"<<'\n';
    }else{
      int d;
      d=arr[n-1]-arr[n-2];
      if(d>=2){
          cout<<"NO"<<'\n';
      }
      else{
        cout<<"YES"<<'\n';
      }
    }
  }



  return 0;
}
