#include<bits/stdc++.h>
using namespace std;

vector<string> arr;
int n;
string x;

bool comp(string &a, string &b){
  string merge1 = a+b, merge2 = b+a;
  if(merge2 >= merge1) return false;
  else return true;
}

int main(){

  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>x;
    arr.push_back(x);
  }
  sort(arr.begin(),arr.end(),comp);
  string ans="";
  for(auto &p:arr) ans+=p;
  if(ans[0] =='0') cout<<0<<'\n';
  else cout<<ans<<'\n';
  return 0;
}
