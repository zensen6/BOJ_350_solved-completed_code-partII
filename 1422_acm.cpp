#include<bits/stdc++.h>
using namespace std;

int n,k;
string x;
vector<string> arr,max_len_str;


bool comp(string a, string b){
  string merge1 = a+b, merge2 = b+a;
  if(merge1 >= merge2) return false; //!merge1.compare(merge2) 했더니 runtimeerror 해결
  else return true;
}

bool max_comp(string &a, string &b){
  return a<b;
}


auto max_ = [](int a, int b){return a>b?a:b;};

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>k>>n;
  int max_len = 0;
  for(int i = 0; i < k; i++){
    cin>>x;
    max_len=max<unsigned>(max_len,x.length());
    arr.push_back(x);
  }
  if(arr.size() > 1) sort(arr.begin(),arr.end(),comp);
  if(arr.size() > 1) reverse(arr.begin(),arr.end());
  for(auto&p:arr){
    if(p.length() == max_len) max_len_str.push_back(p);
    //cout<<p<<'\n';
  }

  if(max_len_str.size()>1) sort(max_len_str.begin(),max_len_str.end(),max_comp);
  if(max_len_str.size()>1) reverse(max_len_str.begin(),max_len_str.end());
  bool once = false;
  for(int i=0;i<k;i++){
      cout<<arr[i];
      if(!arr[i].compare(max_len_str[0]) && !once){
        once=true;
        for(int i=0;i<n-k;i++) cout<<max_len_str[0];
      }
  }
  //cout<<ans<<'\n';
  return 0;
}
