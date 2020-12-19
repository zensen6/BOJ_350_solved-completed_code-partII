#include<bits/stdc++.h>
using namespace std;

int main(){

  int t,x;
  cin>>t;
  while(t--){
    cin>>x;
    if(x > 45) cout<<-1<<'\n';
    else{
      if(x>=1 && x <= 9) cout<<x<<'\n';
      else if(x>=10 && x <= 17){
        cout<<x-9<<"9"<<'\n';
      }
      else if(x>=18 && x <= 24){
        cout<<x-17<<"89"<<'\n';
      }
      else if(x>=25 && x <= 30){
        cout<<x-24<<"789"<<'\n';
      }
      else if(x>=31 && x <= 35){
        cout<<x-30<<"6789"<<'\n';
      }
      else if(x>=36 && x <= 39){
        cout<<x-35<<"56789"<<'\n';
      }
      else if(x>=40 && x <= 42){
        cout<<x-39<<"456789"<<'\n';
      }
      else if(x>=43 && x <= 44){
        cout<<x-42<<"3456789"<<'\n';
      }
      else{
        for(int i = 1; i<=9;i++) cout<<i;
        cout<<'\n';
      }
    }


  }



  return 0;
}
