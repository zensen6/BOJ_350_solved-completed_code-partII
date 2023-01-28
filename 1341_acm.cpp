#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a,b;
ll state = 0LL;

int main(){

  cin>>a>>b;
  ll A = a, B = b-a;
  bool done = false;
  int l;
  for(l=1;l<=60;l++){
    state = state << 1LL;
    state |= 1LL;
    if(state % b == 0){
      done = true;
      break;
    }
  }
  if(done){
    ll N = state / b;
    string ans = "";
    ll AN = A*N; //2
    ll BN = B*N; //1
    for(int i=0;i<l;i++){
      if(AN & (1LL << i)){
        ans += "*";
      }else{
        ans += "-";
      }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
  }else{
    cout<<-1<<'\n';
  }

  return 0;
}
