#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

string ori;
int n;
int d[52][52];
vector<string> words;

int ans = MAX;

int func(string a, string b){
  int c = 0;
  int len = a.length();
  for(int i=0;i<len;i++){
    if(a[i]!=b[i]) c++;
  }
  return c;
}

int main(){

  for(int i=0;i<52;i++){
    for(int j=0;j<52;j++) d[i][j] = MAX;
  }
  cin>>ori;
  cin>>n;
  words = vector<string> (n);
  for(int i=0;i<n;i++){
    cin>>words[i];
  }
  int len = ori.length();

  for(int index = 0; index < len; index++){
    for(int j=0;j<n;j++){
      int s = words[j].length();
      if(s-1 > index) continue;
      else{
        string ori_sorted = ori.substr(index-s+1,s);
        sort(ori_sorted.begin(), ori_sorted.end());
        string words_sorted = words[j];
        sort(words_sorted.begin(),words_sorted.end());
        if(ori_sorted.compare(words_sorted)) continue;
        if(index == s-1){
          d[index][j] = min(d[index][j],func(ori.substr(0,index+1),words[j]));
        }else{
          for(int k=0;k<52;k++){
            if(d[index-s][k]!=MAX){
              d[index][j] = min(d[index][j],d[index-s][k]+func(ori.substr(index-s+1,s),words[j]));
            }
          }
        }
      }
    }
  }

  int ans=MAX;
  for(int i=0;i<52;i++){
    ans = min(ans,d[len-1][i]);
  }
  if(ans==MAX) cout<<-1<<'\n';
  else cout<<ans<<'\n';

  return 0;
}
