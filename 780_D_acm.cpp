#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int tc;
int n;

bool comp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
  return a.first > b.first;
}

int main(){

  cin>>tc;
  while(tc--){
    vector<pair<int,pair<int,int>>> ans;
    cin>>n;
    vector<int> arr(n,0);
    vector<pair<int,int>> notzero;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      if(arr[i]!=0){
        if(notzero.size()==0){
          notzero.push_back({i,i});
        }else if(notzero[notzero.size()-1].second == i-1){
          notzero[notzero.size()-1].second = i;
        }else if(notzero[notzero.size()-1].second < i-1){
          notzero.push_back({i,i});
        }
      }
    }
    for(auto& [left,right]:notzero){
      int two=0,l=left,r=right,minus=0;
      for(int i=left;i<=right;i++){
        if(abs(arr[i])==2) two++;
        if(arr[i]<0) minus++;
      }
      if(minus%2==0){ // entire
        ans.push_back({two,{left,right}});
      }else{
        while(arr[l]>0) l++;
        while(arr[r]>0) r--;
        if(l+1<=right){
          two=0;
          for(int i=l+1;i<=right;i++) if(abs(arr[i])==2) two++;
          ans.push_back({two,{l+1,right}});
        }
        if(r-1>=left){
          two=0;
          for(int i=left;i<=r-1;i++) if(abs(arr[i])==2) two++;
          ans.push_back({two,{left,r-1}});
        }
      }
    }
    sort(ans.begin(),ans.end(),comp);
    if(ans.size()==0){
      cout<<n<<" "<<0<<'\n';
    }else{
      cout<<ans[0].second.first<<" "<<n-ans[0].second.second-1<<'\n';
    }

  }


  return 0;
}
