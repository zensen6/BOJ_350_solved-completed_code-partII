#include<bits/stdc++.h>
using namespace std;

int h,w,n,x,y;
vector<pair<int,int>> arr;

int main(){

  cin>>h>>w;
  cin>>n;
  arr = vector<pair<int,int>>(n,{0,0});
  for(int i = 0 ;i < n; i++){
    cin>>x>>y;
    arr[i].first = x;
    arr[i].second = y;
  }
  int A[2] = {h,w};
  int area = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      for(int k = 0; k < 2; k++){
        if(max(arr[i].first,arr[j].first) <= A[k] && arr[i].second + arr[j].second <= A[1-k]){
          area = max(area, arr[i].first*arr[i].second + arr[j].first*arr[j].second);
        }else if(max(arr[i].first,arr[j].second) <= A[k] && arr[i].second + arr[j].first <= A[1-k]){
          area = max(area, arr[i].first*arr[i].second + arr[j].first*arr[j].second);
        }else if(max(arr[i].second,arr[j].first) <= A[k] && arr[i].first + arr[j].second <= A[1-k]){
          area = max(area, arr[i].first*arr[i].second + arr[j].first*arr[j].second);
        }else if(max(arr[i].second,arr[j].second) <= A[k] && arr[i].first + arr[j].first <= A[1-k]){
          area = max(area, arr[i].first*arr[i].second + arr[j].first*arr[j].second);
        }
      }
    }
  }
  cout<<area<<'\n';


  return 0;
}
