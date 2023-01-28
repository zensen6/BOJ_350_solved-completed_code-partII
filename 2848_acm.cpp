#include<bits/stdc++.h>
using namespace std;

vector<string> word;
int n;
bool check[26];
vector<int> node[26];
map<int,int> isUsed;
int ind[26], totalUsed;

int make_dictionary(){
  for(int i=0;i<n;i++){
    int len=word[i].length();
    for(int j=0;j<len;j++) isUsed[word[i][j]-'a']=1;
  }
  for(int i=0;i<n-1;i++){
    int minlen=min(word[i].length(),word[i+1].length());
    for(int j=0;j<minlen;j++){
      if(word[i][j]!=word[i+1][j]){
        int a = word[i][j]-'a', b = word[i+1][j]-'a';
        node[a].push_back(b);
        isUsed[a]=1;
        isUsed[b]=1;
        ind[b]++;
        break;
      }else if(j==minlen-1&&word[i+1].length()==minlen&&word[i].length()>minlen){
        return 0;
      }
    }
  }
  return 1;
}


int main(){

  cin>>n;
  word = vector<string> (n);
  for(int i = 0 ; i < n; i++){
    cin>>word[i];
  }
  int ret = make_dictionary();
  if(!ret){
    cout<<"!"<<'\n';
    return 0;
  }
  vector<int> order;
  int indZero = 0;
  queue<int> q;
  for(auto &p: isUsed){
    if(ind[p.first]==0){
      indZero++;
      q.push(p.first);
      order.push_back(p.first);
    }
  }
  if(!indZero){
    cout<<"!"<<'\n';
    return 0;
  }
  while(!q.empty()){
    int here = q.front();
    q.pop();
    int tmpindZero=0;
    for(auto &next:node[here]){
      ind[next]--;
      if(!ind[next]){
        tmpindZero++;
        indZero=max(indZero,tmpindZero);
        order.push_back(next);
        q.push(next);
      }
    }
  }
  totalUsed=isUsed.size();
  if(order.size() == totalUsed){
    if(indZero>=2){
      cout<<"?";
    }else{
      for(auto &p:order) cout<<char(p+'a');
    }
    cout<<'\n';
  }else cout<<"!"<<'\n';

  return 0;
}
