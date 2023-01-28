#include<bits/stdc++.h>
#define MAX 101
using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n=3,m,s;

bool dfs(int x){

  c[x] = true;
  for(int i = 0; i < a[x].size(); i++){
    int t = a[x][i];
    if(d[t] == 0 || (!c[d[t]] && dfs(d[t]))){
      d[t] = x;
      d[x] = t;
      return true;
    }
  }
  return false;
}

int main(){
  a[1].push_back(100);
  a[1].push_back(200);
  a[1].push_back(300);
  a[2].push_back(100);
  a[3].push_back(200);
  int count = 0;
  fill(c,c+MAX,false);
  for(int i = 1; i <= 3; i++){
      fill(c,c+MAX,false);
      if(dfs(i)) count++;
  }

  for(int i = 1; i <= 3; i++){
    cout<<d[i]<<" ";
    for(int i = 1; i <= 3; i++) cout<<c[i]<<" ";
    cout<<'\n';
  }
  return 0;
}
