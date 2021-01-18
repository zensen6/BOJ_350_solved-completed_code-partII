#include<bits/stdc++.h>
using namespace std;

int main(){

  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int sum = a+b+c+d;
  if((sum)&1) cout<<"NO"<<'\n';
  else if((a+b== sum/2) || (a+c==sum/2) || (a+d==sum/2)) cout<<"YES"<<'\n';
  else if(a==sum/2 || b==sum/2 || c==sum/2 || d==sum/2) cout<<"YES"<<'\n';
  else cout<<"NO"<<'\n';

  return 0;
}
