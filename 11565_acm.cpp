#include<bits/stdc++.h>
using namespace std;

string A,B;

int main(){

  cin>>A;
  cin>>B;
  int sa= A.length(), sb = B.length();
  int aone = 0, bone = 0;
  for(int j=0;j<sa;j++) if(A[j] == '1') aone++;
  for(int j=0;j<sb;j++) if(B[j] == '1') bone++;
  if(aone&1){
    if(aone + 1 >= bone)cout<<"VICTORY"<<'\n';
    else cout<<"DEFEAT"<<'\n';
  }else{
    if(aone >= bone) cout<<"VICTORY"<<'\n';
    else cout<<"DEFEAT"<<'\n';
  }

  return 0;
}
