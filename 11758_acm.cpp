#include<bits/stdc++.h>
using namespace std;

int x1,x2,x3,y_1,y_2,y_3;

int cross(int x1, int x2, int y_1, int y_2){
  return x1*y_2-x2*y_1 >= 0? (x1*y_2-x2*y_1 == 0? 0 : 1) : -1;

}

int main(){

  cin>>x1>>y_1;
  cin>>x2>>y_2;
  cin>>x3>>y_3;
  cout<<cross(x2-x1,x3-x1,y_2-y_1,y_3-y_1)<<'\n';

  return 0;
}
