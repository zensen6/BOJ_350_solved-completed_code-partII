#include<bits/stdc++.h>
#define MAX 300000
using namespace std;

int t,n,x,y,arr[MAX+2];

bool comp1(pair<int,int> &a, pair<int,int> &b){
  if(a.second == b.second) return a.first > b.first;
  return a.second < b.second;
}

bool comp(pair<int,int> &a, pair<int,int> &b){
  if(a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}

struct SegmentTree{

  void init(){
    memset(arr,0,sizeof(arr));
  }
  int sum(int start ,int end, int node, int i, int j){ // [start,end]: sum 하려는구간,[i,j]:탐색
    if(i>end || j<start) return 0;
    else if(start<=i && j<=end){
      return arr[node];
    }
    int ret1 = sum(start, end, node*2, i,(j+i)/2);
    int ret2 = sum(start, end, node*2+1,(i+j)/2+1,j);
    return ret1 + ret2;
  }
  void change(int start, int end, int node, int index){// [start,end]: 탐색
    if(start > index || end < index) return;
    else if(start == end){
       arr[node]++;
       return;
    }
    int mid = (start+end)/2;
    change(start, mid, node*2, index);
    change(mid+1, end, node*2+1, index);
    arr[node] = arr[node*2] + arr[node*2+1];
  }

};

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--){
    vector<pair<int,int>> v;
    SegmentTree ST;
    ST.init();
    long long ans = 0;
    int c=0;
    cin>>n;
    for(int i = 0 ; i < n; i++){
      cin>>x>>y;
      v.push_back({x,y});
    }
    sort(v.begin(),v.end(),comp1);

    for(int i = 0 ; i < n; i++){
      /*
      if(i != 0){
        if(v[i].second != v[i-1].second) v[i].second = ++c;
        else v[i].second = c;
      }
      else v[i].second = c;
      */
      v[i].second = c++;
    }
    sort(v.begin(),v.end(),comp);

    for(int i = 0; i < n; i++){
      ans += ST.sum(v[i].second,c-1,1,0,c-1);
      ST.change(0,c-1,1,v[i].second);
    }
    cout<<ans<<'\n';
  }


  return 0;
}
