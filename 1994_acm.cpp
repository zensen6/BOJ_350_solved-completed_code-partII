#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
map<int,int> m_;
int n,x,ans=0,max_val=0;

bool proc(int k){
  int last = 0,subans=2;
  for(int m=0;m<n-k+1;m++){
    for(int l=m+1;l<n;l++){
      int d=arr[l]-arr[m],c=2,plus=d;
      if(d > (arr[n-1]-arr[m])/(k-1)) break;
      while(m_[arr[l]+plus] && arr[l]+plus<=max_val){
        plus+=d;
        c++;
      }
      subans=max(subans,c);
      if(subans>=k) return 1;
    }
  }
  return 0;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>x;
    arr.push_back(x);
    m_[x]++;
    max_val = max(max_val,x);
  }
  sort(arr.begin(),arr.end()); //first sort next erase
  arr.erase(unique(arr.begin(),arr.end()),arr.end());
  n = arr.size();

  for(auto p: m_){
    ans = max(ans,p.second);
  }
  int lo = max(2,ans), hi = n;
  while(lo <= hi){
    int mid = (lo+hi)>>1;
    if(proc(mid)){
      ans = max(ans,mid);
      lo = mid+1;
    }else{
      hi = mid-1;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
