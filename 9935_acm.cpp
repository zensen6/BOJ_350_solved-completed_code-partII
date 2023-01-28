#include<bits/stdc++.h>
using namespace std;

string A,E;
stack<char> st;

int main(){

  cin>>A;
  cin>>E;
  int lenA = A.length(), lenE = E.length();
  for(auto& p:A){
    st.push(p);
    if(st.size()>=lenE){
      string n = "";
      for(int i=0;i<lenE;i++){
        n+=st.top();
        st.pop();
      }
      reverse(n.begin(),n.end());
      if(n.compare(E)){
        for(int i=0;i<lenE;i++){
          st.push(n[i]);
        }
      }
    }
  }
  string ans="";
  while(!st.empty()){
    ans+=st.top();
    st.pop();
  }
  reverse(ans.begin(),ans.end());
  ans = (ans == "" ? "FRULA": ans);
  cout<<ans<<'\n';

  return 0;
}
