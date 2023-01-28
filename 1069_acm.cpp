#include<bits/stdc++.h>
using namespace std;

int x,y,d,t;
bool check[1001][1001];

bool inrange(int ny, int nx){
  return ny>=0&&ny<=1000&&nx>=0&&nx<=1000;
}

void bfs(){
  check[y][x] = true;
  queue<pair<int,pair<int,int>>> q;
  q.push({0,{y,x}});
  while(!q.empty()){
    auto f = q.front();
    int count = f.first, r = f.second.first, c = f.second.second;
    if(r>=d){
      if(!check[r-d][c]){
        check[r-d][c] = true;

      }
    }
    if(c>=d){

    }
    if(r>=d && c>=d){

    }
  }
}


int main(){


  cin>>x>>y>>d>>t;
  cout<<fixed<<setprecision(9);

  if(t>=d) cout<<max(x,y)<<'\n';
  else{




  }


  return 0;
}
