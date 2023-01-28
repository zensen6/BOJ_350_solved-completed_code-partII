#include<bits/stdc++.h>
using namespace std;

int tc,a,b,c,init_start=1,init_end=1000000;
  int node[3003000];

struct SegmentTree{

  void init(){ // init with only flavor value, count=0
    memset(node,0,sizeof(node));
  }

  void inserting(int start, int end, int node_index, int flavor, int c){// by query inserting(1,1000000,1,b,c);
    if(end<flavor||start>flavor) return;
    node[node_index]+=c;
    if(start==end) return;
    int mid=(start+end)>>1;
    inserting(start,mid,2*node_index,flavor,c);
    inserting(mid+1,end,2*node_index+1,flavor,c);
    return;
  }
  int deleting(int start, int end, int node_index, int start_order, int order){//by query deleting(1,1000000,1,1,b);
    if(start==end){
      node[node_index]--;
      return start;
    }
    int mid=(start+end)>>1,ret;
    if(start_order+node[2*node_index]-1>=order){
      node[node_index]--;
      return deleting(start,mid,2*node_index,start_order,order);
    }else{
      node[node_index]--;
      return deleting(mid+1,end,2*node_index+1,start_order+node[2*node_index],order);
    }
  }
};


int main(){


  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>tc;
  SegmentTree ST;
  ST.init();
  while(tc--){
    cin>>a;
    if(a&1){
      cin>>b;
      int ret=ST.deleting(init_start,init_end,1,1,b);
      cout<<ret<<'\n';
    }else{
      cin>>b>>c;
      ST.inserting(init_start,init_end,1,b,c);
    }
  }

  return 0;
}
