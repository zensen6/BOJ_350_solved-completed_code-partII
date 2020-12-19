#include<bits/stdc++.h>
using namespace std;

int main(){

  int t,n;
  string x;
  cin>>t;
  while(t--){
    cin>>n;
    cin>>x;
    int two = 0, one = 0;
    if(n < 4) cout<<"NO"<<'\n';
    else if(x[0]=='2' && x[1] == '0' && x[n-1]=='0' && x[n-2]=='2') cout<<"YES"<<'\n';
    else if(x[0]=='2' && x[n-1]=='0' && x[n-2]=='2' && x[n-3] == '0') cout<<"YES"<<'\n';
    else if(x[0]=='2' && x[1] == '0'&& x[2]=='2' && x[n-1]=='0') cout<<"YES"<<'\n';
    else if(x[0]=='2' && x[1]=='0' && x[2]=='2'&& x[3]=='0') cout<<"YES"<<'\n';
    else if(x[n-4]=='2' && x[n-3]=='0' && x[n-2]=='2'&&x[n-1]=='0')cout<<"YES"<<'\n';
    else{
      cout<<"NO"<<'\n';
    }


  }



  return 0;
}
