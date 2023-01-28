#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
ll n, arr[1000002], index_[1000002], ans = 0;
ll node[3500010];

struct SegmentTree{

  void meminit(){
    memset(node,0,sizeof(node));
  }
  void change(int start, int end, int node_index, int index){
    if(index > end || index < start) return;
    if(start == end){
      ++node[node_index];
      return;
    }
    int mid = (start+end)>>1;
    change(start, mid, 2*node_index, index);
    change(mid+1, end, 2*node_index+1, index);
    node[node_index] = node[2*node_index] + node[2*node_index+1];
    return;
  }
  ll sum(int start, int end, int node_index, int i, int j){
    if(j < start || i > end) return 0;
    if(i <= start && end <= j) return node[node_index];
    int mid = (start + end)>>1;
    ll l = sum(start, mid, 2*node_index, i, j);
    ll r = sum(mid+1, end, 2*node_index+1, i, j);
    return node[node_index] = l + r;
  }
};

int main(){

  cin>>n;
  for(int i = 0 ; i < n; i++){
    cin>>arr[i];
    index_[arr[i]] = i;
  }
  SegmentTree Tree;
  Tree.meminit();
  for(int i = 1; i <= n; i++){
    int inserting = index_[i];
    ans += Tree.sum(0,n-1,1,inserting+1,n-1);
    Tree.change(0,n-1,1,inserting);
  }
  cout<<ans<<'\n';


  return 0;
}
