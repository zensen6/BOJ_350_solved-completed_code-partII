#include<bits/stdc++.h>
using namespace std;

multimap<string,string> from_to, to_from;
set<string> read;
string x;
vector<string> ans;

void proc(){
  read.clear();
  from_to.clear();
  to_from.clear();
  return;
}

int main(){
  cin.tie(NULL);
	ios_base::sync_with_stdio(false);

  while(1){
    getline(cin,x);
    if(x[0] =='E'){
      ans.push_back(x);
      break;
    }else{
      if(x[0] == 'W'){
        int idx1 = x.find(" ");
        int idx2 = x.find(" ", idx1 + 1);
        int idx3 = x.find(" ", idx2 + 1);
        string a = x.substr(idx1 + 1, idx2 - idx1 - 1);
        string b = x.substr(idx3 + 1, x.size() - idx3 - 1);
        if(read.count(b) != 0){
          ans.push_back("WAIT");
          proc();
        }else if(from_to.count(b) != 0 || to_from.count(a) != 0){
          ans.push_back("WAIT");
          proc();
        }else if(to_from.count(b) != 0){
          ans.push_back("WAIT");
          proc();
        }
        from_to.insert(make_pair(a,b));
        to_from.insert(make_pair(b,a));
        ans.push_back(x);
      }else if(x[0] == 'R'){
        int idx1 = x.find(" ");
        string a = x.substr(idx1 + 1, x.size() - idx1 - 1);
        if(to_from.count(a) != 0){
          ans.push_back("WAIT");
          proc();
        }
        read.insert(a);
        ans.push_back(x);
      }
    }

  }


  for(int i=0;i<ans.size();i++) cout<<ans[i]<<'\n';


  return 0;
}
