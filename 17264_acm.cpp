#include<bits/stdc++.h>
using namespace std;

string name, win;
int n,p,w,l,g;
map<string, int> name_;

int main(){

  cin>>n>>p;
  cin>>w>>l>>g;
  for(int i = 0 ; i < p; i++){
    cin>>name>>win;
    if(win[0] =='W') name_[name] = 1;
  }
  int ans = 0;
  for(int i = 0 ; i < n; i++){
    cin>>name;
    if(name_[name]) ans+=w;
    else{
      ans -= l;
      ans = max(ans,0);
    }
    if(ans>=g){ cout<<"I AM NOT IRONMAN!!"<<'\n';return 0;
    }
  }
  cout<<"I AM IRONMAN!!"<<'\n';

  return 0;
}
