#include<bits/stdc++.h>
using namespace std;

int tc,w,n,x,y,r,p[1010];

int Find(int x){
  if(x==p[x]) return x;
  return p[x] = Find(p[x]);
}

void Union(int x, int y){
  int x1=p[x], y1=p[y];
  if(x1<y1){
    p[y1]=x1;
    Find(y);
  }else{
    p[x1]=y1;
    Find(x);
  }
  return;
}

double dist(int x1,int y1,int x2,int y2){
  return sqrt(pow(x1-x2,2)+pow(y1-y2,2)+.0); // double return할때는 반드시 Pow 사용해야한다.
}

bool comp(pair<double,pair<int,int>>&a, pair<double,pair<int,int>>&b){
  return a.first < b.first; // double sort할때는 이렇게 써도 괜찮다.
}

int main(){

  cin>>tc;
  while(tc--){
    double ans = 0;
    int wall_right=1001, wall_left=0;
    cin>>w;
    cin>>n;
    vector<pair<int,pair<int,int>>> Circle (n+2);
    vector<pair<double,pair<int,int>>> edge;
    edge.push_back({w+.0,{wall_left,wall_right}});
    for(int i=0;i<=1001;i++) p[i]=i;
    for(int i=1;i<=n;i++){
      cin>>x>>y>>r;
      Circle[i].first=r;
      Circle[i].second.first=x;
      Circle[i].second.second=y;
    }
    for(int i=1;i<=n;i++){
      int rad=Circle[i].first,posx=Circle[i].second.first,posy=Circle[i].second.second;
      edge.push_back({max(posx-rad+.0,.0),{wall_left,i}});
      edge.push_back({max(w-posx-rad+.0,.0),{wall_right,i}});
    }
    for(int i=1;i<n;i++){
      for(int j=i+1;j<=n;j++){
        int rad1=Circle[i].first,posx1=Circle[i].second.first,posy1=Circle[i].second.second;
        int rad2=Circle[j].first,posx2=Circle[j].second.first,posy2=Circle[j].second.second;
        double d=dist(posx1,posy1,posx2,posy2);
        edge.push_back({max(d-rad1-rad2+.0,.0),{i,j}});
      }
    }
    sort(edge.begin(),edge.end(),comp);
    cout.precision(6);
    cout<<fixed;
    for(auto &e:edge){
      double cost=e.first;
      int from=e.second.first, to=e.second.second;
      if(Find(from) != Find(to)){
        Union(from,to);
        ans=cost;
      }
      if(Find(wall_left)==Find(wall_right)){
          cout<<ans/2+.0<<'\n';
          break;
      }
    }
  }



  return 0;
}
