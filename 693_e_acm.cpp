#include<bits/stdc++.h>
using namespace std;

int tc,n;
vector<pair<pair<int,int>,int>> v;

bool comp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
  if(a.first.first < b.first.first) return true;
  else if(a.first.first == b.first.first) return a.first.second <= b.first.second;
  return false;
}

int main(){


  cin>>tc;
  while(tc--){
    v.clear();
    cin>>n;
    vector<int> a(n+1,0), b(n+1,0);
    for(int i = 1 ; i <= n; i++){
      cin>>a[i]>>b[i];
      v.push_back({{a[i],b[i]},i});
      v.push_back({{b[i],a[i]},i});
    }

    if(n==1){
      cout<<-1<<'\n';

    }else{
      sort(v.begin(),v.end(),comp);

      int len = v.size();
      int max_ = 0;
      int arr[200002];
      for(int i = 0; i < 200002; i++) arr[i] = -1;
      vector<int> d(v.size(),1000000001),ind(v.size(),0);
      d[0] = v[0].first.second;
      ind[0] = v[0].second;
      for(int i = 1; i< len; i++){
        if(v[i].first.second <= d[i-1]){
          d[i] = v[i].first.second;
          ind[i] = v[i].second;
        }else{
          d[i] = d[i-1];
          ind[i] = ind[i-1];
        }
      }



      for(int i = len-1; i >= 1; i--){
        if(d[i-1] < v[i].first.second){
          arr[v[i].second] = ind[i-1];
        }
      }
      for(int i = 1; i <= n; i++) cout<<arr[i]<<'\n';
    }


  }
  return 0;
}
