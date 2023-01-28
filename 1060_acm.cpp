#include<bits/stdc++.h>
#define INF 1000000001ULL
#define MIN 0
using namespace std;

typedef unsigned long long ll;

int l,n,x;
vector<int> arr;
vector<pair<ll,ll>> range;


struct comp{

  bool operator()(pair<ll,ll> &a, pair<ll,ll> &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
  }
};


int main(){

  cin>>l;
  for(int i=0;i<l;i++){
    cin>>x;
    arr.push_back(x);
  }
  cin>>n;
  sort(arr.begin(),arr.end());
  if(arr[0]-MIN-1 > 0) range.push_back({MIN+1,arr[0]-1});
  for(int i=1;i<l;i++){
    if(arr[i]-arr[i-1]-1>0) range.push_back({arr[i-1]+1,arr[i]-1});
  }
  range.push_back({arr[l-1]+1,INF});
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,comp> pq;
  for(int i=0;i<l;i++) pq.push({0,arr[i]});
  for(auto &[left,right]: range){
    if(right == INF){
      for(int i=0;i<100;i++) pq.push({INF*INF+10000ULL,left+i});
    }
    else{
      ll len = right-left+1;
      if(len > 100){
        for(int i=0;i<50;i++){
          pq.push({(len-i)*(i+1)-1,left+i});
          pq.push({(len-i)*(i+1)-1,right-i});
        }
      }else{
        for(int i=0;i<len;i++){
          pq.push({(len-i)*(i+1)-1,left+i});
        }
      }
    }
  }
  int c=0;
  while(!pq.empty()){
    auto f=pq.top();
    pq.pop();
    cout<<f.second<<" ";
    if(++c == n) break;
  }

  return 0;
}
