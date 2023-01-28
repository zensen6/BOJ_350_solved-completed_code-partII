#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> p;
vector<pair<int,int>> arr;
string d[51];


bool comp(pair<int,int> &a, pair<int,int> &b){
  if (a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}

string num(int a, int c){
  string nu = "";
  for(int k=0;k<c;k++) nu += to_string(a);
  return nu;
}

string bigger(string &a, string &b){
  if(a.length() > b.length()) return a;
  else if(a.length() < b.length()) return b;
  else if(a < b) return b;
  return a;
}

int main(){

  cin>>n;
   p =vector<int>(n,0);
  for(int i=0;i<n;i++){
    cin>>p[i];
    //arr.push_back({p[i],i});
  }
  cin>>m;

  for(int i=1;i<n;i++){
    arr.push_back({p[i],i});
  }
  arr.push_back({p[0],0});

  for(int i=0;i<51;i++) d[i] = "X";
  d[0] = ".";

  sort(arr.begin(),arr.end(),comp);
  for(int i=0;i<n;i++){
    for(int j=m/arr[i].first; j>=0; j--){
      for(int k=m;k>=0;k--){
        if(k-j*arr[i].first >= 0){
          if(d[k-j*arr[i].first] != "X"){
            if(k-j*arr[i].first == 0){
              if(!(arr[i].second == 0 && (j>=2))){
                string a = num(arr[i].second, j);
                sort(a.begin(),a.end());
                reverse(a.begin(),a.end());
                if(d[k] == "X") d[k] = a;
                else d[k] = bigger(d[k],a);
              }
            }else{
              string cpm = d[k-j*arr[i].first] + num(arr[i].second, j);
              sort(cpm.begin(),cpm.end());
              reverse(cpm.begin(),cpm.end());
              if(!(cpm.length() >= 2 && !cpm.substr(0,1).compare("0")))d[k] = bigger(d[k],cpm);
            }
          }
        }
      }
    }
  }
  string ans = "";
  for(int i=m;i>=1;i--){
    //cout<<d[i]<<'\n';
    if(d[i] == "X") continue;
    ans = bigger(d[i],ans);
  }
  cout<<ans<<'\n';

  return 0;
}
