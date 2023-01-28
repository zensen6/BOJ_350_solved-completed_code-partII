#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n,m,r,a,b,c;
int d[101][101];

vector<int>arr(101);


int main(){

  for(int i = 0; i < 101; i++){
    for(int j = 0; j < 101; j++){
      if(i==j){
        d[i][j] = 0;
      }
      else{
        d[i][j] = INF;
      }
    }
  }

  cin>>n>>m>>r;
  for(int i = 1; i <= n; i++){
    cin>>arr[i];
  }
  for(int i = 0; i < r; i++){
    cin>>a>>b>>c;
    d[a][b] = min(d[a][b], c);
    d[b][a] = min(d[b][a], c);
  }
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(d[i][k] + d[k][j] < d[i][j]){
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
  int ans = 0;
  for(int start = 1; start <= n; start++){
    int s = 0;
    for(int forward = 1; forward <= n; forward++){
      if(d[start][forward] <= m){
        s += arr[forward];
      }
    }
    ans = max(ans,s);
  }
  cout<<ans<<'\n';


  return 0;
}
