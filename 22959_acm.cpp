#include<bits/stdc++.h>
#define MAX 2000000001
using namespace std;

typedef long long ll;

struct SegmentTree{
  int arr[200001];
  int min_node[600100];
  ll node[600100];
  ll sum_init(int node_index, int i, int j){
    if(i == j) return node[node_index] = arr[i];
    int mid = (i+j)>>1;
    ll left = sum_init(node_index*2, i, mid);
    ll right = sum_init(1+node_index*2, mid+1, j);
    return node[node_index] = left+right;
  }

  ll sum_of_range(int node_index, int i, int j, int start, int end){
    if(start > j || end < i) return 0;
    else if(i >= start && end >= j) return node[node_index];
    int mid = (i+j)>>1;
    ll left = sum_of_range(node_index*2, i, mid, start, end);
    ll right = sum_of_range(1+node_index*2, mid+1, j, start, end);
    return left+right;
  }


  ll change_sum_(int node_index, int i, int j, int index, int value){
    if(index == i && index == j){
      ll gap = value - arr[index];
      arr[index] += gap;
      node[node_index] += gap;
      return gap;
    }else if(index < i || index > j) return node[node_index];
    int mid = (i+j)>>1;
    ll gap;
    if(index >= i && index <= mid){
      gap = change_sum_(node_index*2,i,mid,index,value);
      node[node_index] += gap;
    }else{
      gap = change_sum_(1+node_index*2,mid+1,j,index,value);
      node[node_index] += gap;
    }
    return gap;
  }

  int min_init(int node_index, int i, int j){
    if(i == j) return min_node[node_index] = arr[i];
    int mid = (i+j)>>1;
    ll left = min_init(node_index*2,i,mid);
    ll right = min_init(1+node_index*2,mid+1,j);
    return min_node[node_index]= min(left,right);
  }

  int change_min_(int node_index, int i, int j, int index, int value){
    if(index == i && index == j){
      min_node[node_index] = arr[index];
      return value;
    }else if(index < i || index > j) return min_node[node_index];
    int mid = (i+j)>>1;
    int left = change_min_(node_index*2,i,mid,index,value);
    int right = change_min_(1+node_index*2,mid+1,j,index,value);
    return min_node[node_index] = min(left,right);
  }

  int min_of_range(int node_index, int i, int j, int start, int end){
    if(start > j || end < i) return MAX;
    else if(i == j) {
      return min_node[node_index];
    }
    else if(i >= start && end >= j) return min_node[node_index];
    int mid = (i+j)>>1;
    ll left = min_of_range(node_index*2, i, mid, start, end);
    ll right = min_of_range(1+node_index*2, mid+1, j, start, end);
    return min(left,right);
  }
};

int main(){

  ll n,q,t,i_,j_;
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  SegmentTree S;
  for(int i = 0 ; i < 600100; i++) S.node[i]= 0;
  memset(S.min_node,0,sizeof(S.min_node));
  for(int l = 0; l < n; l++){
    cin>>S.arr[l];
  }

  S.sum_init(1,0,n-1);
  S.min_init(1,0,n-1);
  cin>>q;

  for(int i = 0; i < q; i++){
    cin>>t>>i_>>j_;
    if(t&1){
      S.change_sum_(1, 0, n-1, i_-1, j_);
      S.change_min_(1, 0, n-1, i_-1, j_);
    }else{
      pair<int,int> left_range = {0,i_-1};
      int mid;
      while(left_range.first <= left_range.second){
        mid = (left_range.first + left_range.second) >> 1;
        if(S.min_of_range(1,0,n-1,mid,i_-1)>=j_){
          left_range.second = mid-1;
        }
        else{
          left_range.first = mid+1;
        }
      }
      int left_ans = mid;
      pair<int,int> right_range = {i_-1,n-1};
      while(right_range.first <= right_range.second){
        mid = (right_range.first + right_range.second) >> 1;
        if(S.min_of_range(1,0,n-1,i_-1,mid)>=j_){
          right_range.first = mid+1;
        }
        else{
          right_range.second = mid-1;
        }
      }
      int right_ans  = mid;
      cout<<S.sum_of_range(1,0,n-1,left_range.first,right_range.second)<<'\n';
    }
  }

  return 0;
}
