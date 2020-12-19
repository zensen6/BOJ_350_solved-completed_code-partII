#include<bits/stdc++.h>
using namespace std;

char arr[11][11];
int n,m,k;
string s;
vector<string> v;

int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
map<pair<pair<int,int> ,int>, int> m_;

int proc(int y, int x, string s, int index){
  if(m_[{{y,x},index}]) return m_[{{y,x},index}];
  if(index == s.length()-1){
    return m_[{{y,x},index}] = 1;
  }
  int sum_ = 0;
  for(int dir = 0 ; dir < 8; dir++){
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0) ny = n-1;
    if(nx < 0) nx = m-1;
    if(ny >= n) ny = 0;
    if(nx >= m) nx = 0;
    if(s[index+1] == arr[ny][nx])
      sum_ += proc(ny,nx,s,index+1);
  }
  return m_[{{y,x},index}] = sum_;

}


int main(){

  scanf("%d %d %d", &n,&m,&k);
  getchar();
  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%1c", &arr[i][j]);
    }
    getchar();
  }

  for(int i = 0 ; i < k; i++){
    cin>>s;
    int ans = 0;
    m_.clear();
    for(int y = 0 ; y < n; y++){
      for(int x = 0; x < m; x++){
        if(arr[y][x] == s[0]){
          ans += proc(y,x,s,0);
        }
      }
    }
    cout<<ans<<'\n';
  }



  return 0;
}
