#include<bits/stdc++.h>
using namespace std;

bool check[1000001];
int d[1000001], n;
vector<int> save;


void going(int here, int len, int index, string k, int match){

  if(index == len){
    if(stoi(k) >= match){
      int si = stoi(k);
      if(here + si <= n){
        if(!d[here + si])
          save.push_back(si);
      }
    }
    return;
  }else if(index > len){
    return;
  }
  k += "4";
  going(here, len, index+1, k, match);
  k[index] = '7';
  going(here, len, index+1, k, match);

}

void generating(int here, int x){
  save.clear();
  string s = "";
  string y = to_string(x);
  int to;
  if(to_string(n - here)[0] < '4'){
    to = to_string(n - here).length() -1;
  }else{
    to = to_string(n - here).length();
  }
  for(int i = y.length(); i <= to; i++){
    going(here, i, 0, s, x);
  }
  return;
}


bool proc(){

  queue<pair<int,pair<int,int>>> q;
  generating(0,0);
  for(auto p: save){
    check[p] = true;
    q.push({p,{p,1}});
    d[p] = p;
  }
  sort(save.begin(),save.end());
  int s = save.size();
  while(!q.empty()){
    auto f = q.front();
    q.pop();
    int here = f.first, added = f.second.first, count = f.second.second;
    if(here == n) return true;
    if(added+here > n) continue;
    //vector<int> k = generating(here, added);
    auto l = lower_bound(save.begin(), save.end(), added) - save.begin();
    for(int i = l; i < s; i++){
      if(save[i] + here <= n && !check[save[i]+here]){
        check[here + save[i]] = true;
        d[here+save[i]] = save[i];
        q.push({here+save[i],{save[i],count+1}});
      }
    }
  }
  return false;
}

void track(int here, vector<int> &ans){
  if(here == 0) return;
  ans.push_back(d[here]);
  track(here - d[here], ans);
  return;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(check, false, sizeof(check));
  memset(d,0,sizeof(d));
  cin>>n;
  if(n <= 0) cout<<-1<<'\n';
  else if(!proc()){
    cout<<-1<<'\n';
  }
  else{
    vector<int> ans;
    track(n, ans);
    reverse(ans.begin(), ans.end());
    for(auto p: ans) cout<<p<<" ";
    cout<<'\n';
  }

  //vector<int> ans = generating(n);
  //for(auto k: ans) cout<<k<<'\n';
  return 0;
}
