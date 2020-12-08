#include<bits/stdc++.h>
using namespace std;

int main(){

  int t,n,m,x;
  cin>>t;
  while(t--){
    cin>>n>>m;
    int c = 0;
    int arr[101];
    memset(arr,0,sizeof(arr));
    for(int i = 0 ; i < n; i++){
      cin>>x;
      arr[x]++;
    }
    for(int i = 0 ; i < m; i++){
      cin>>x;
      arr[x]++;
      if(arr[x] > 1) c++;
    }
    cout<<c<<'\n';
  }





  return 0;
}
