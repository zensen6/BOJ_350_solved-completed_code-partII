#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
queue<pair<int,bool>> q;
int solution(int n){
  int ans = 0;
  m[n] = true;




}

int dfs(int num, bool outer){
  int next = num-1;
  if(next%3==0){
      dfs(next/3, false);
  }


}


int main(){

  int  n;
  cin>>n;
  cout<<solution(n)<<'\n';
  return 0;

}
