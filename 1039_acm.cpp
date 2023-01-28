#include<bits/stdc++.h>
using namespace std;

int n,k,d[10],use=0,ans;
vector<int> place;
string x;

string swap_s(string a, int i, int j){
  char tmp;
  tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
  return a;
}


void proc(string x, int len, int start, int remain){
  if(remain == 0 || start == len){
    if(!(remain&1) || !remain){
      ans = max(ans,stoi(x));
    }else{
      bool two = false;
      for(int i = 0; i < 10; i++){
        if(d[i] >= 2) two = true;
      }
      if(two){
        ans = max(ans,stoi(x));
      }else{
        char t = x[len-1];
        x[len-1] = x[len-2];
        x[len-2] = t;
        ans = max(ans,stoi(x));
      }
    }
    return;
  }
  bool done = false;
  for(int next = start+1; next < len; next++){
    if((int)(x[next]-'0') == place[start] && (int)(x[start]-'0') != place[start]){
      done = true;
      proc(swap_s(x,start,next), len, start+1, remain-1);
    }
  }
  if(!done) proc(x,len,start+1,remain);
  return;
}



int main(){

  memset(d,0,sizeof(d));
  cin>>n>>k;
  ans = 0;
  x = to_string(n);
  int len = x.length();
  for(int i = 0; i < len; i++){
    d[(int)(x[i]-'0')]++;
    place.push_back((int)(x[i]-'0'));
  }
  sort(place.begin(),place.end());
  reverse(place.begin(),place.end());
  if(len == 1) cout<<-1<<'\n';
  else if(len == 2 && d[0] == 1) cout<<-1<<'\n';
  else{
    proc(x,len,0,k);
    cout<<ans<<'\n';
  }

  return 0;
}
