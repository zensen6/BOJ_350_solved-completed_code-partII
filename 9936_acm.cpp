#include<bits/stdc++.h>
#define INF -1000000000000LL
using namespace std;
typedef long long ll;

ll d[1001][1001][1<<3];
int n,k,arr[1001][3];

int state[12][3] = {
  {0,0,0},
  {1,1,1},
  {2,2,1},
  {4,4,1},
  {3,3,2},
  {5,5,2},
  {7,4,2},
  {7,1,2},
  {6,6,2},
  {6,0,1},
  {3,0,1},
  {7,7,3}
};

ll calc(int index, int state){
  ll ret=0;
  if(state&1) ret += arr[index][0];
  if(state&2) ret += arr[index][1];
  if(state&4) ret += arr[index][2];
  return ret;
}

ll go(int index, int domino, int cur){
  if(domino < 0) return INF;
  ll &ret = d[index][domino][cur];
  if(ret != INF) return ret;
  if(index == n){
    if(domino==0 && cur==0) return ret = 0;
    else return INF;
  }
  //ret=0; 일반적으로 음수 가져가는 문제에서는 ret=0 세팅하면 안됨: 만약 남은 모든 칸이 음수면 답이 음수인데 0으로 매겨서 오답임
  for(int i=0;i<12;i++){
    int cur_state = state[i][0];
    int next_state = state[i][1];
    int num = state[i][2];
    if(cur_state&cur) continue;
    ret = max<ll>(ret, calc(index, cur_state|cur)+go(index+1,domino-num,next_state));
  }
  return ret;
}


int main(){

  cin>>n>>k;

  for(int i=0;i<1001;i++){
    for(int j=0;j<1001;j++){
      for(int k=0;k<8;k++) d[i][j][k] = INF;
    }
  }

  for(int i=0;i<n;i++){
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
  }
  cout<<go(0,k,0)<<'\n';
}
