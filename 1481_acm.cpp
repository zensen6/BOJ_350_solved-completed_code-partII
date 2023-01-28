#include<bits/stdc++.h>
using namespace std;

int n,d, arr[11][11];
int row[11][11], col[11][11];
int rc[11], cc[11];

bool proc(int r, int c){
  if(r<n&&(d-rc[r] > n-c+1)|| c<n&&(d-cc[c] > n-r+1)) return false;
  if(r == n && c == 0){
    for(int i=0;i<n;i++){
      for(int j=0;j<d;j++){
        if(row[i][j]<=0||col[i][j]<=0) return false;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<arr[i][j]<<" ";
      }
      cout<<'\n';
    }
    return true;
  }
  for(int num=0;num<d;num++){
    if(row[r][num] < n-d+1 || col[c][num] < n-d+1){
      row[r][num]++;
      col[c][num]++;
      if(row[r][num]==1) rc[r]++;
      if(col[c][num]==1) cc[c]++;
      arr[r][c] = num;
      if(proc((c==n-1?r+1:r),(c==n-1?0:c+1))) return true;
      if(row[r][num]==1) rc[r]--;
      if(col[c][num]==1) cc[c]--;
      row[r][num]--;
      col[c][num]--;
    }
  }
  return false;
}

int main(){

  cin>>n>>d;
  proc(0,0);
  return 0;
}
