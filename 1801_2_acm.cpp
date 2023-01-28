#include<bits/stdc++.h>
using namespace std;

int n,L[1<<16];
vector<int> arr;
bool dp[1<<16],pos[180];

int ans = -1;
void calc(int index, int width_set, int height_set){
  if(index == n){
    if(dp[width_set]&&dp[height_set]) ans=max(ans,(L[width_set]>>1)*(L[height_set]>>1));
    return;
  }
  calc(index+1,width_set|(1<<index),height_set);
  calc(index+1,width_set,height_set|(1<<index));
  calc(index+1,width_set,height_set);
  return;
}

int main(){

  cin>>n;
  arr = vector<int> (n,0);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=1;i<(1<<n);i++){
    for(int num=0;num<n;num++){
      L[i] += ((1<<num)&i)? arr[num]:0;
    }
    if(L[i] % 2) continue;
    pos[0] = true;
    for(int j=1;j<=(L[i]>>1);j++) pos[j]=false;
    for(int j=0;j<n;j++){
      if((1<<j)&i)
        for(int k=L[i]>>1; k>=arr[j]; k--){
          if(pos[k-arr[j]]) pos[k]=true;
        }
    }
    if(pos[L[i]>>1]) dp[i] = true;
  }
  calc(0,0,0);
  cout<<ans<<'\n';


  return 0;
}
