#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int check[1010];
int l[4] = {1,5,10,50};
int n;
int ans = 0;

void proc(int index, int lastnum, int num){
  if(index == n && !check[num]){
    check[num] = 1;
    ans += 1;
    return;
  }
  int lastindex;
  for(int i = 0; i < 4; i++)
    if(l[i] >= lastnum){
      lastindex = i;
      break;
    }
  for(int i = lastindex; i < 4; i++){
    proc(index+1, l[i], num + l[i]);
  }
  return;
}

int main(){

  memset(check, 0, sizeof(check));
  cin>>n;
  proc(0,1,0);
  //for(int i = 1; i < 1001; i++) ans += (check[i]? 1: 0);
  cout<<ans<<'\n';
  return 0;
}
