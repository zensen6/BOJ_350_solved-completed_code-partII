#include<bits/stdc++.h>
using namespace std;
int n,g,a,b;
string x;
multiset<int> s;
map<int,int> m;
vector<pair<pair<int,int>,int>> v;

bool comp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
  if(a.first.first == b.first.first) return a.first.second < b.first.second;
  return a.first.first < b.first.first;
}
int main(){
    cin>>n>>g;
    int c = 0;
    for(int i = 0 ; i < n; i++){
      cin>>a>>b>>x;
      v.push_back({{a, b},(x[0]=='-'?-1:1)*stoi(x.substr(1,x.length()-1))});
    }
    sort(v.begin(),v.end(),comp);
    for(int i = 0 ; i < n+3; i++) s.insert(0);
    for(auto &p: v){
      int id = p.first.second, delta = p.second, curmax = *prev(s.end()), second_max = *prev(prev(s.end()));
      if(m[id] == curmax && second_max == curmax){
        if(delta != 0){
          c++;
        }
      }else if(m[id] == curmax && second_max != curmax){
        if(second_max >= m[id] + delta){
          c++;
        }
      }else if(m[id] + delta >= curmax && delta > 0){
        c++;
      }
      s.erase(s.find(m[id]));
      m[id] += delta;
      s.insert(m[id]);
    }
    cout<<c<<'\n';

  return 0;
}
