#include<bits/stdc++.h>
using namespace std;

int n;
bool d[81][81][81][81];

int main(){

  int s=0;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
    s+=arr[i];
  }
  d[0][0][0][0] = true;
  vector<tuple<int,int,int,int>> v;
  for(int i=0;i<n;i++){
    int val=arr[i];
    for(int w1=(s>>1)-1;w1>=0;w1--){
      for(int h1=(s>>1)-w1;h1>=0;h1--){
        for(int w2=(s>>1)-1;w2>=w1;w2--){
          for(int h2=(s>>1)-w2;h2>=h1;h2--){
            if(w1+h1>(s>>1) || w2+h2>(s>>1) || w1+h2>(s>>1) || w2+h1>(s>>1)) continue;
            if(d[w1][w2][h1][h2]){
              if(w1+val>w2) d[w2][w1+val][h1][h2] = true;
              else d[w1+val][w2][h1][h2] =true;
              if(w2+val<w1) d[w2+val][w1][h1][h2] =true;
              else d[w1][w2+val][h1][h2] =true;
              if(h1+val>h2) d[w1][w2][h2][h1+val] =true;
              else d[w1][w2][h1+val][h2] =true;
              if(h2+val < h1) d[w1][w2][h2+val][h1] =true;
              else d[w1][w2][h1][h2+val] =true;
            }
          }
        }
      }
    }
  }
  int ans = -1;
  for(int i=1;i<80;i++){
    for(int j=1;j<80;j++){
      if(d[i][i][j][j]) ans=max(ans,i*j);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
