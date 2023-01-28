#include<bits/stdc++.h>
using namespace std;

int n;
char t;
string x="";
map<string, int> m;

bool win(string &a){
  int c=0;
  for(int i=0;i<2*n-1;i+=2){
    if(a[i]!=a[i+1] && a[i]=='O') c++;
    else if(a[i]!=a[i+1] && a[i]=='X') c--;
  }
  return c>0?true:false;
}

int bfs(){
  int ret=1000000;
  m[x]=1;
  if(win(x)) return ret=0;
  queue<pair<string,int>>q;
  q.push({x,1});
  while(!q.empty()){
    auto t=q.front();
    q.pop();
    string y=t.first;
    int c=t.second;
    for(int pos=1;pos<2*n;pos++){
      char tmp=y[pos];
      string token1 = y.substr(0,pos);
      string token2 = pos<2*n-1? y.substr(pos+1,2*n-pos-1) : "";
      string nstr ="";
      nstr += tmp;
      nstr += token1;
      nstr += token2;
      if(m[nstr] == 0){
        m[nstr] = c+1;
        if(win(nstr)) ret=min(ret,c);
        q.push({nstr,c+1});
      }
    }
  }
  return ret;
}

int main(){

  cin>>n;
  for(int i=0;i<2*n;i++){
    cin>>t;
    x+=t;
  }
  cout<<bfs()<<'\n';


  return 0;
}
