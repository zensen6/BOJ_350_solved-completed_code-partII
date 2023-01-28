#include<iostream>
#include<deque>
#include<list>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
using namespace std;

string x,y;

int main(){

  cin>>x;
  cin>>y;
  x.insert(x.length(),y,1,2);
  cout<<x<<'\n';



  return 0;
}
