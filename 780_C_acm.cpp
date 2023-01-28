#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int tc;
int n;
string x;

int main(){

  cin>>tc;
  while(tc--){
    map<char,int> m;
    cin>>x;
    int len =x.length(), c=0;
    for(int i=0;i<len;i++){
      m[x[i]]++;
      if(m[x[i]]==2){
        c-=2;
        m.clear();
      }
      c++;
    }
    cout<<c<<'\n';
  }


  return 0;
}
