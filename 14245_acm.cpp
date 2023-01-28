#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,t,a,b,c;
ll arr[500002];
ll lazy[1500010];

struct SegmentTree{

  void init(){
    memset(lazy,0,sizeof(lazy));
  }

  void lazy_update(int start, int end, int node_index){
    if(lazy[node_index]){
      if(start!=end){
        lazy[2*node_index]^=lazy[node_index];
        lazy[2*node_index+1]^=lazy[node_index];
      }else{
        arr[start]^=lazy[node_index];
      }
      lazy[node_index]=0;
    }
    return;
  }

  void update_(int start, int end, int node_index, int l, int r, int c){
    lazy_update(start, end, node_index);
    if(end<l || start>r) return;
    if(l<=start&&end<=r){
      lazy[node_index] ^= c;
      return;
    }
    int mid=(start+end)>>1;
    update_(start,mid,2*node_index,l,r,c);
    update_(mid+1,end,2*node_index+1,l,r,c);
    return;
  }
  ll query(int start, int end, int node_index, int index){
    lazy_update(start,end,node_index);
    if(end<index || start>index) return 0;
    if(start==end) return arr[start];
    int mid = (start+end)>>1;
    return query(start,mid,2*node_index,index) + query(mid+1,end,2*node_index+1,index);
  }


};


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  SegmentTree ST;

  ST.init();

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  cin>>m;
  while(m--){
    cin>>t;
    if(t&1){
      cin>>a>>b>>c;
      ST.update_(0,n-1,1,a,b,c);
    }else{
      cin>>a;
      cout<<ST.query(0,n-1,1,a)<<'\n';
    }
  }



  return 0;
}
