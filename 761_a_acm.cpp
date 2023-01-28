#include<bits/stdc++.h>
using namespace std;

int tc, alpha[26];
string S,T;



int main(){

  cin>>tc;
  while(tc--){
    string ans="";
    memset(alpha,0,sizeof(alpha));
    cin>>S;
    cin>>T;
    for(auto &p:S) alpha[p-'a']++;
    if(alpha[0]&&alpha[1]&&alpha[2]&&!T.compare("abc")){
        for(int i=0;i<alpha[0];i++) ans+="a";
        for(int i=0;i<alpha[2];i++) ans+="c";
        for(int i=0;i<alpha[1];i++) ans+="b";
        for(int i=3;i<26;i++){
          for(int c=0;c<alpha[i];c++){
            ans += char(i+'a');
          }
        }
      }else{
      for(int i=0;i<26;i++){
        for(int c=0;c<alpha[i];c++){
          ans += char(i+'a');
        }
      }
    }
    cout<<ans<<'\n';
  }

  return 0;
}
