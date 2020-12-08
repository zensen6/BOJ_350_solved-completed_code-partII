#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){

  int t,n,x;
  cin>>t;

  while(t--){

    cin>>n;
    vector<int>v(n+1,0);
    vector<int>gap(n+1,0);
    vector<int>pot(n+1,0);
    for(int i = 1 ; i <= n; i++){
      cin>>v[i];
      if(i==2){
        pot[i-1] = abs(v[1]-v[2]);
        gap[i-1] = abs(v[1]-v[2]);
      }
      else if(i>2 && i<n){
        pot[i-1] = abs(v[i-1]-v[i-2]) + abs(v[i-1]-v[i]) - abs(v[i] - v[i-2]);
        gap[i-1] = abs(v[i] - v[i-1]);
      }
      else if(i==n){
        pot[i-1] = abs(v[i-1]-v[i-2]) + abs(v[i-1]-v[i]) - abs(v[i] - v[i-2]);
        pot[i] = abs(v[i]-v[i-1]);
        gap[i-1] = abs(v[i] - v[i-1]);
      }
    }
    int m = -1, index;
    for(int i = 1 ; i <= n; i++){
      if(pot[i] > m){
        m = pot[i];
        index = i;
      }
    }
    //
    //for(int i = 1; i <= n-1; i++) cout<<pot[i]<<" ";
    //cout<<index<<'\n';
    //
    if(index == 1) gap[1] = 0;
    else if(index == n) gap[n-1] = 0;
    else{
        gap[index] = abs(v[index-1]-v[index+1]);
        gap[index-1] = 0;
    }
    //for(int i = 1; i <= n-1; i++) cout<<gap[i]<<" ";
    ll s = 0;
    for(int i = 1 ; i < n; i++) s+=gap[i];
    cout<<s<<'\n';
  }



  return 0;
}
