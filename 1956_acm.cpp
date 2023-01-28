#include<bits/stdc++.h>
#define MAX 200000000000LL
using namespace std;

typedef long long ll;

ll d[402][402];

int v,e,x,y,c;
ll ans = MAX;


int main(){

  memset(d, -1, sizeof(d));

  cin>>v>>e;
  for(int i = 0 ; i < e; i++){
    cin>>x>>y>>c;
    d[x][y] = c;
  }
  for(int i = 1; i <= v; i++){
    for(int j = 1; j <= v; j++){
      if(d[i][j] == -1) d[i][j] = MAX;
    }
  }

  for(int k = 1; k <= v; k++){
    for(int i = 1; i <= v; i++){
      for(int j = 1; j <= v; j++){
        d[i][j] = min<ll>(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for(int i = 1; i <= v; i++){
    if(d[i][i] != MAX) ans = min<ll>(ans, d[i][i]);
  }


  if(ans == MAX) cout<<-1<<'\n';
  else cout<<ans<<'\n';


  return 0;
}
