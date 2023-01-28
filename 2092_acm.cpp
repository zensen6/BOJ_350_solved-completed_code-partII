#include<bits/stdc++.h>
#define MOD 1000000
using namespace std;

int t,a,s,b,x,d[4000][4000];
vector<int> arr;
map<int,int> m;


int mod(int x){
  if(x<0) return (x+MOD)%MOD;
  return x%MOD;
}

int main(){

  memset(d,0,sizeof(d));
  cin>>t>>a>>s>>b;
  for(int i = 0; i < a; i++){
    cin>>x;
    m[x]++;
    arr.push_back(x);
  }
  sort(arr.begin(),arr.end());
  reverse(arr.begin(),arr.end());
  arr.erase(unique(arr.begin(),arr.end()),arr.end());

  int first_g = arr[0];
  for(int k_ = 0; k_ <= b; k_++){
    int process = 0;
    int k = k_;
    for(auto &group: arr){
      process += m[group];
      for(int p = 0; p <= min(k,m[group]); p++){
        if(first_g == group)
          d[a-process][p] = 1;
        else
          d[a-process][k] = mod(d[a-process][k] + d[a-process+m[group]][k-p]);
      }
    }
  }
  int ans = 0;
  for(int k = s; k <= b; k++)
    ans = mod(ans+d[0][k]);


  cout<<ans<<'\n';

  return 0;
}
