#include<bits/stdc++.h>
using namespace std;

bool canreach(int distance, vector<int>& r, int n, int target){
  int next = 1, cur = 0, len = r.size(), c = 0;
  while(next != len){
    if(r[next] - r[cur] < target){
      next++;
      c++;
    }else{
      cur = next;
      next++;
    }
  }
  return c<=n;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(),rocks.end());
    int answer = 0, len = rocks.size();
    vector<int> r(len+2,0);
    rocks.push_back(distance);
    for(int i = 1 ; i <= len + 1; i++){
      r[i] = rocks[i-1];
    }
    vector<int> ans;
    int low = 1, hi = distance;
    while(hi>=low){
      int mid = (low+hi)>>1;
      if(canreach(distance, r, n, mid)){
        low = mid+1;
        ans.push_back(mid);
      }else{
        hi = mid-1;
      }
    }
    sort(ans.begin(),ans.end());
    answer = ans[ans.size()-1];
    return answer;
}


int main(){

  int dis,l,n,x;
  vector<int> rocks;
  cin>>dis;
  cin>>l>>n;
  for(int i = 0 ; i < l; i++){
    cin>>x;
    rocks.push_back(x);
  }
  cout<<solution(dis,rocks,n)<<'\n';

  return 0;
}
