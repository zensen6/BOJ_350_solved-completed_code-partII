#include<bits/stdc++.h>
using namespace std;

int n;
double x,y,w,h;
vector<pair<pair<double,double>,pair<double,double>>> v;

int main(){

  cin>>n;
  for(int i = 0 ; i < n; i++){
    cin>>x>>y>>w>>h;
    v.push_back({{x,y},{w,h}});
  }
  


  return 0;
}
