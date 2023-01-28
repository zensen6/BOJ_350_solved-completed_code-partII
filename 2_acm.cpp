#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<map>
using namespace std;

int arr[100001], n;
vector<int> adj[100001];
int ans = 0;
int check[100001];
int c = 0;
map<int,int> finished;
void dfs(int here){
  c++;
  if(check[here]){
    ans = max(ans,c - check[here]);
    c--;
    return;
  }
  check[here] = c;
  for(auto &p: adj[here]){
    if(!finished[p]) dfs(p);
  }
  finished[here] = 1;
  return;

}

int main(){

  cin>>n;
  for(int i = 1; i <= n; i++){
    cin>>arr[i];
    adj[i].push_back(i+arr[i]);
  }
  memset(check,0,sizeof(check));
  for(int i = 1; i <= n; i++){
    if(!check[i]){
      memset(check,0,sizeof(check));
      dfs(i);
    }
  }
  cout<<ans<<'\n';

  return 0;
}
