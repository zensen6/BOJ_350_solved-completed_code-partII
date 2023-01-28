#include<bits/stdc++.h>
using namespace std;


int n,k,u;
vector<int> node[1001];
int sccId[1001];
int group_num[1001];
int maximum[1001];
int id = 0;
int visited[1001];
int visited_ = 0;
bool check[1001];
int ind[1001];
bool d[1001];
vector<int> scc_group[1001];
stack<int> st;

int scc(int here){
  int ret = visited_;
  visited[here] = visited_++;
  st.push(here);
  for(auto &p: node[here]){
    if(visited[p] == -1){
      ret = min(ret, scc(p));
    }else if(sccId[p] == -1){
      ret = min(ret, visited[p]);
    }
  }
  if(ret == visited[here]){
    int c = 0;
    while(!st.empty()){
      int f = st.top();
      st.pop();
      c++;
      sccId[f] = id;
      scc_group[id].push_back(f);
      if(f == here){
        group_num[id] = c;
        break;
      }
    }
    id++;
  }
  return ret;
}

void make_ind(int here){
  check[here] = true;
  for(auto &p: node[here]){
    if(sccId[here] != sccId[p]) ind[sccId[p]]++;
    if(check[p] == 0)  make_ind(p);
  }
  return;
}

///            scc group 설정을 안함 모든 같은 id 안의 원소들에 대해 곁가지 구해야함
int dfs(int here){
  int ret = group_num[sccId[here]];
  check[sccId[here]] = true;
  for(auto &a:scc_group[sccId[here]]){
    for(auto &p: node[a]){
      if(!check[sccId[p]]){
        if(sccId[p] != sccId[here]){
          ret += dfs(p);
        }
      }
    }
  }
  return ret;
}


int main(){

  memset(visited, -1, sizeof(visited));
  memset(sccId, -1, sizeof(sccId));

  cin>>n>>k;


  for(int i=1;i<=n;i++){
    cin>>u;
    node[u].push_back(i);
  }
  for(int i=1;i<=n;i++){
    if(sccId[i] == -1) scc(i);
  }
  for(int i=1;i<=n;i++){
    if(check[i] == 0) make_ind(i);
  }


  memset(check, 0, sizeof(check));


  for(int i=1;i<=n;i++){
    if(ind[sccId[i]]==0 && check[sccId[i]] == 0){
      maximum[sccId[i]] = dfs(i);
    }
  }

  d[0] = true;
  for(int i=0;i<id;i++){
    for(int j=k;j>=0;j--){
      for(int z=maximum[i];z>=group_num[i];z--){
        if(j-z >=0){
          if(d[j-z]) d[j] = true;
        }
      }
    }
  }
  for(int i=k;i>=0;i--){
    if(d[i]){
      cout<<i<<'\n';
      break;
    }
  }

  return 0;
}
