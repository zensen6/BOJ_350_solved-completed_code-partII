#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int tc,n,m,k,u,v,c,d,dist[101][10001]; // dist[N][M] : M원 남긴 N까지의 최소 소요시간
                                       // dist[i][M] + cost[i][j](=l <= M) >= dist[j][M-l] 일때 갱신

vector<pair<int,pair<int,int>>> edge[101];
int dijkstra(){
  for(int i=0;i<101;i++){
    for(int j=0;j<10001;j++){
      dist[i][j]=INF;
    }
  }
  for(int M=0;M<10001;M++) dist[1][M]=0;
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
  pq.push({0,{1,0}});
  while(!pq.empty()){
    auto t=pq.top();
    pq.pop();
    int target=t.second.first,cost=t.first,money=t.second.second;
    if(cost>dist[target][m-money]) continue;
    for(auto &p:edge[target]){
      int next=p.first, c_=p.second.first,d_=p.second.second; //c_:money
      if(m-money>=c_){
        if(dist[target][m-money]+d_ < dist[next][m-money-c_]){
          dist[next][m-money-c_]=dist[target][m-money]+d_;
          pq.push({dist[next][m-money-c_],{next,money+c_}});
        }
      }
    }
  }
  int ans=INF;
  for(int i=0;i<=m;i++){
    ans=min(ans,dist[n][i]);
  }
  return ans;
}

int main(){

  cin>>tc;
  while(tc--){
    for(int i=0;i<101;i++)edge[i].clear();
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
      cin>>u>>v>>c>>d;
      edge[u].push_back({v,{c,d}});
    }
    int res=dijkstra();
    if(res==INF) cout<<"Poor KCM"<<'\n';
    else cout<<res<<'\n';
  }

  return 0;
}
