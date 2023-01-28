#include<bits/stdc++.h>
using namespace std;

int w,b;
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
bool check[4][4];
char board[4][4];
string x,input_;
char delimeter[10000];
vector<string> arr;

bool inrange(int y, int x){
  return y>=0&&y<4&&x>=0&&x<4;
}

bool comp(string a, string b){
  if(a.length() != b.length()) return a.length() < b.length();
  return a > b;
}

bool match(int dict_index, int index, int n, int y, int x){
  check[y][x] = true;
  bool res = false;
  if(index == n-1) return res = true;
  for(int dir = 0; dir < 8; dir++){
    int ny = y + dy[dir], nx = x + dx[dir];
    if(inrange(ny,nx)){
      if(!check[ny][nx] && arr[dict_index][index+1] == board[ny][nx]){
        check[ny][nx] = true;
        res = match(dict_index, index+1, n, ny,nx) | res;
        check[ny][nx] = false;
      }
    }
  }
  check[y][x] = false;
  return res;
}

int score_function(int len){
  if(len <= 2 && len >= 1) return 0;
  else if(len <= 4) return 1;
  else if(len <= 5) return 2;
  else if(len <= 6) return 3;
  else if(len <= 7) return 5;
  else if(len == 8) return 11;
  else return 0;
}


int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>w;
  for(int i = 0; i < w; i++){
    cin>>x;
    arr.push_back(x);
  }

  sort(arr.begin(),arr.end(),comp);
  arr.erase(unique(arr.begin(),arr.end()),arr.end());
  w = arr.size();
  cin>>b;
  for(int i = 0; i < b; i++){
    int s = 0, index1_ = 0, co = 0;
    for(int j = 0 ; j < 4; j++){
      cin>>input_;
      for(int k = 0; k < 4; k++){
        board[j][k] = input_[k];
      }
    }
    for(int dict_index = 0; dict_index < w; dict_index++){
      bool done = false;
      for(int y_ = 0; y_ < 4; y_++){
        for(int x_ = 0 ; x_ < 4; x_++){
          if(arr[dict_index][0] == board[y_][x_]){
            memset(check,false,sizeof(check));
            if(match(dict_index,0,arr[dict_index].length(),y_,x_)){
              done = true;
              co += 1;
              s += score_function(arr[dict_index].length());
              index1_ = dict_index;
              break;
            }
          }
        }
        if(done) break;
      }
    }
    cout<<s<<" "<<arr[index1_]<<" "<<co<<'\n';
  }

  return 0;
}
