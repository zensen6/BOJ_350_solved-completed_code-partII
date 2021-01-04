#include<bits/stdc++.h>
using namespace std;

int tc,n,x;

int main(){

  cin>>tc;
  while(tc--){
    cin>>n;
    int sum = 0;
    vector<int> v(n,0);
    int arr[3];
    arr[1] = 0;
    arr[2] = 0;
    for(int i = 0 ; i < n; i++){
      cin>>v[i];
      sum += v[i];
      arr[v[i]]++;
    }
    if(sum&1) cout<<"NO"<<'\n';
    else{
      if(arr[2]&1){
        if(arr[1] < 2) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
      }else{
        cout<<"YES"<<'\n';
      }
    }

  }


  return 0;
}
