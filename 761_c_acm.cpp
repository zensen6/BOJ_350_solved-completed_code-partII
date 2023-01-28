#include<bits/stdc++.h>
using namespace std;

int tc,n,x;

int main(){

  cin>>tc;
  while(tc--){
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
      cin>>arr[i];
    }
    sort(arr.begin()+1,arr.end());
    int c=0;
    bool possible=true;
    for(int i=1;i<=n;i++){
      if(arr[i]!=i){
        if(arr[i]&1){
          if((arr[i]>>1)>=i) c++;
          else {
            possible=false;
            break;
          }
        }
        else{
          if((arr[i]>>1)-1>=i) c++;
          else {
              possible=false;
              break;
          }
        }
      }
    }
    if(possible)cout<<c<<'\n';
    else cout<<-1<<'\n';
  }



  return 0;
}
