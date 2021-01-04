#include<bits/stdc++.h>
using namespace std;

int dist(int ny, int nx, int i, int j){
  return abs(ny-i) + abs(nx-j);
}

bool check[11][11];

bool proc(int n, int max_, int mid){
  memset(check,false,sizeof(check));
  int c = 0;
  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!check[i][j]){
        check[i][j] = true;
        c++;
        for(int y = 0; y < n; y++){
          for(int x = 0; x < n; x++){
            if(dist(i,j,y,x) < mid) check[y][x] = true;
          }
        }
      }
    }
  }
  return c >= max_;

}

int solution(int n, int m, vector<vector<int>> timetable){

  int max_ = 0;
  for(int t = 600; t <= 1320; t++){
    int tmp = 0;
    for(int i = 0; i < m; i++){
      if(timetable[i][0] <= t && t <= timetable[i][1]){
        tmp++;
      }
    }
    max_ = max(tmp,max_);
  }
  int answer;
  if(max_ <= 1 || m <= 1) answer = 0;
  else{
    int lo=1,hi=2*(n),mid;
    vector<int> ans;

    while(lo<=hi){
      memset(check,false,sizeof(check));
      mid = (lo+hi)>>1;
      if(proc(n,max_,mid)){
        ans.push_back(mid);
        lo = mid+1;
      }else{
        hi = mid-1;
      }
    }
    sort(ans.begin(),ans.end());
    answer = ans[ans.size()-1];
  }

  return answer;

}

int main(){

  int n,m,t1,t2;
  vector<vector<int>> timetable;
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    vector<int> t;
    cin>>t1>>t2;
    t.push_back(t1);
    t.push_back(t2);
    timetable.push_back(t);
  }

  cout<<solution(n,m,timetable)<<'\n';

  return 0;
}
