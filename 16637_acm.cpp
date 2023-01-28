#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans = -100000000000;
int n;
string x;
bool check[20];

ll evaluate(ll x, ll y, char eval){
  if(eval == '+'){
    return x + y;
  }else if(eval == '-'){
    return x - y;
  }else return x * y;

}

void proc(int index, ll num){
  if(index >= n){
    ans = max(ans,num);
    return;
  }
  if(index == 0){
    //choose
    if(index < n-1)
      proc(index + 4, evaluate((ll)(x[index]-'0'), (ll)(x[index+2]-'0'), x[index+1]));
    //not
    proc(index + 2, (ll)(x[index] - '0'));
  }else{
    //choose
    if(index < n-1){
      //cout<<index<<" "<<num<<'\n';
      proc(index + 4, evaluate(num,evaluate((ll)(x[index]-'0'),(ll)(x[index+2]-'0'),x[index+1]),x[index-1]));
    }
    //not
    proc(index + 2, evaluate(num,(ll)(x[index]-'0'),x[index-1]));
  }
  return;

}


int main(){

  cin>>n;
  cin>>x;
  proc(0,0);
  cout<<ans<<'\n';

  return 0;
}
