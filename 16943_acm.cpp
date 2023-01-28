#include<bits/stdc++.h>
using namespace std;

int a,b,n, ans = -1;
vector<int> A;
bool check[10];

bool checkbit(int x, int y){
  int i = 1, j = 1;
  while(x / i >= 1) i*=10;
  while(y / j >= 1) j*=10;
  i/=10, j/=10;
  return (i==j);
}

void proc(int index, int num){
  if(index == n){
    if(num > 0){
      if(checkbit(num,a))
        ans = max(ans, num);
    }
    return;
  }
  for(int i = 0; i < n; i++){
    if(!check[i] && num*10 + A[i] < b){
      check[i] = true;
      proc(index + 1, num*10 + A[i]);
      check[i] = false;
    }
  }
  return;
}


int main(){

  memset(check,0,sizeof(check));
  cin>>a>>b;
  string x = to_string(a);
  A = vector<int>(x.length(),0);
  for(int i = 0 ; i < x.length(); i++){
    A[i] = (int)(x[i] - '0');
  }
  n = x.length();
  sort(A.begin(), A.end());
  reverse(A.begin(),A.end());

  proc(0,0);
  cout<<ans<<'\n';

  return 0;

}
