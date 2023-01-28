#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int n,x,y,u,v;
int d[52][102][102];
int lastnum[52][102][102];

vector<pair<int,int>> arr;
vector<int> trace;

int proc(int index, int Xsum, int Ysum){
  int &ret = d[index][Xsum][Ysum];
  if(ret != MAX) return ret;
  if(index == 0){
    if(Xsum==x && Ysum==y) return ret=0;
    else return ret=MAX;
  }
  ret = min(ret, proc(index-1,min(x,Xsum+arr[index].first),min(y,Ysum+arr[index].second))+1);
  ret = min(ret, proc(index-1,Xsum,Ysum));
  return ret;
}

/*
void track(int index, int Xsum, int Ysum){
  if(index==n+1){
    return;
  }
  if(d[index-1][Xsum][Ysum]!= MAX && d[index-1][Xsum][Ysum] == d[index][Xsum][Ysum]){
    //cout<<"As";
    track(index-1,Xsum,Ysum);
  }
  else if(d[index-1][min(x,Xsum+arr[index-1].first)][min(y,Ysum+arr[index-1].second)] == d[index][Xsum][Ysum]+1){
    trace.push_back(index);
    track(index-1,min(x,Xsum+arr[index-1].first),min(y,Ysum+arr[index-1].second));
  }
  return;
}
*/

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0;i<52;i++){
    for(int j=0;j<102;j++){
      for(int k=0;k<102;k++){
        d[i][j][k] = MAX;
        lastnum[i][j][k] = MAX;
      }
    }
  }

  cin>>n>>x>>y;
  arr = vector<pair<int,int>>(n+1);
  for(int i=1;i<=n;i++){
    cin>>u>>v;
    arr[i] = {u,v};
  }
  //int ans=proc(n,0,0);
  int ans=MAX;
  d[0][0][0] = 0;
  for(int index=1;index<=n;index++){
    for(int Xsum=0;Xsum<=x;Xsum++){
      for(int Ysum=0;Ysum<=y;Ysum++){
        if(d[index-1][Xsum][Ysum] != MAX){
          int X_ = arr[index].first, Y_ = arr[index].second;
          if(d[index][Xsum][Ysum] >= d[index-1][Xsum][Ysum]){
            d[index][Xsum][Ysum] = min(d[index][Xsum][Ysum],d[index-1][Xsum][Ysum]);
            lastnum[index][Xsum][Ysum] = min(lastnum[index][Xsum][Ysum] ,lastnum[index-1][Xsum][Ysum]);
          }
          if(d[index][min(x,Xsum+X_)][min(y,Ysum+Y_)] >= d[index-1][Xsum][Ysum]+1){
            d[index][min(x,Xsum+X_)][min(y,Ysum+Y_)] = min(d[index][min(x,Xsum+X_)][min(y,Ysum+Y_)],d[index-1][Xsum][Ysum]+1);
            lastnum[index][min(x,Xsum+X_)][min(y,Ysum+Y_)] = min(lastnum[index][min(x,Xsum+X_)][min(y,Ysum+Y_)],index);
          }
        }
      }
    }
  }
  ans=min(ans,d[n][x][y]);

  /*
  for(int index=1;index<=n;index++){
    for(int p=0;p<=x;p++){
      for(int q=0;q<=y;q++){
        if(d[index][p][q] != MAX) cout<<index<<" "<<p<<" "<<q<<"   "<<d[index][p][q]<<" "<<lastnum[index][p][q]<<'\n';
      }
    }
  }
  */


  if(ans==MAX){
    cout<<-1<<'\n';
    return 0;
  }else{
    cout<<ans<<'\n';
    cout<<lastnum[n][x][y]<<'\n';
    //track(0,x,y);

    //cout<<trace[0]<<'\n';
  }
  return 0;
}
