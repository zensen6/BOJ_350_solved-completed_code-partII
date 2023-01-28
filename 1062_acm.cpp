#include<bits/stdc++.h>
using namespace std;

int alpha[26],n,k;
vector<string> arr;
vector<int> bit_set;
map<char,int> m;

int main(){

  int c=0;
  for(int i=0;i<26;i++){
    if((char)(i+'a')!='a'&&(char)(i+'a')!='c'&&(char)(i+'a')!='t'&&(char)(i+'a')!='n'&&(char)(i+'a')!='i'){
      m[char(i+'a')]=c++;
    }
  }
  cin>>n>>k;
  arr = vector<string> (n);
  bit_set = vector<int> (n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
    string nstr="";
    int s = 0;
    for(auto &p:arr[i]){
      if(p!='a'&&p!='n'&&p!='c'&&p!='i'&&p!='t'){
        nstr+=p;
        s |= (1<<m[p]);
      }
    }
    arr[i] = nstr;
    bit_set[i] = s;
  }

  int ans=0;
  for(int i=0;i<(1<<22);i++){
    int c_ = 0;
    for(int j=0;j<n;j++){
      if(__builtin_popcount(i)==k-5 && ((i&bit_set[j]) == bit_set[j])){
        c_++;
      }
    }
    ans=max(ans,c_);
  }
  cout<<ans<<'\n';


  return 0;
}
