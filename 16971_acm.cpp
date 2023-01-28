#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m,A[1001][1001];
vector<int> row,col;
vector<pair<ll,int>> col_big,row_big;



ll ans=-1000000000000;
int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  ll in=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>A[i][j];
      if((i==0&&j!=0&&j!=m-1)||(i==n-1&&j!=0&&j!=m-1)||(j==0&&i!=0&&i!=n-1)||(j==m-1&&i!=0&&i!=n-1)){
        A[i][j]*=2;
      }else if(i!=0&&j!=0&&i!=n-1&&j!=m-1){
        A[i][j]*=4;
      }
      in+=A[i][j];
    }
  }
  ll l=0,r=0,u=0,d=0;
  for(int i=0;i<n;i++){
    l+=A[i][0];
    r+=A[i][m-1];
  }
  for(int j=0;j<m;j++){
    u+=A[0][j];
    d+=A[n-1][j];
  }
  for(int j=1;j<m-1;j++){
    ll t=0;
    for(int i=0;i<n;i++){
      t+=A[i][j];
    }
    col_big.push_back({t,j});
  }
  for(int i=1;i<n-1;i++){
    int t=0;
    for(int j=0;j<m;j++){
      t+=A[i][j];
    }
    row_big.push_back({t,i});
  }
  sort(col_big.begin(),col_big.end(),[](pair<ll,int> &a,pair<ll,int> &b){return a.first < b.first;});
  sort(row_big.begin(),row_big.end(),[](pair<ll,int> &a,pair<ll,int> &b){return a.first < b.first;});
  ll coM=max<ll>(l,r),com=min<ll>(l,r),roM=max<ll>(u,d),rom=min<ll>(u,d);
  ll a=0;
  //cout<<col_big[0].first<<'\n';
  for(int i=1;i<col_big.size();i++){
    a+=col_big[i].first;
  }
  if(col_big.size())a+=(col_big[0].first>>1);
  a+=(col_big.size()>=1?coM<<1:coM);
  a+=com;
  ll b=0;
  for(int i=1;i<row_big.size();i++){
    b+=row_big[i].first;
  }
  if(row_big.size())b+=(row_big[0].first>>1);
  b+=(row_big.size()>=1?roM<<1:roM);
  b+=rom;
  cout<<max<ll>(in,max<ll>(a,b))<<'\n';
  //cout<<roM<<" "<<rom<<" "<<row_big[0].first<<'\n';
  return 0;
}
