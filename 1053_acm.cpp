#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

string x, newstr="";
int isPalin[51][51], d[51][51];
int ans = MAX;

void func(string &x, bool change){

  for(int i=0;i<51;i++){
    for(int j=0;j<51;j++){
      d[i][j] = MAX;
      isPalin[i][j] = true;
    }
  }

  int len = x.length();
  for(int i=0;i<len;i++) isPalin[i][i] = true;
  for(int s=2;s<=len;s++){
    for(int i=0;i<len-s+1;i++){
      for(int k=i;k<=(i+s-1);k++){
        if(x[k]!=x[2*i+s-1-k]) isPalin[i][i+s-1] = false;
      }
    }
  }

  for(int i=0;i<len;i++) d[i][i] = 0;
  for(int s=2;s<=len;s++){
    for(int i=0;i<len-s+1;i++){
      if(isPalin[i][i+s-1]) d[i][i+s-1] = 0;
      else{
        d[i][i+s-1] = min(d[i][i+s-1],d[i+1][i+s-1]+1);
        d[i][i+s-1] = min(d[i][i+s-1],d[i][i+s-2]+1);
        d[i][i+s-1] = min(d[i][i+s-1],d[i+1][i+s-2]+(x[i]==x[i+s-1]?0:1));
      }
    }
  }

  ans = min(ans,d[0][len-1]+(change==true?1:0));
  return;

}

int main(){

  cin>>x;
  string nstr = x;
  int len = x.length();
  func(x,false);
  for(int i=0;i<len-1;i++){
    for(int j=i+1;j<len;j++){
      swap(x[i],x[j]);
      func(x,true);
      swap(x[i],x[j]);
    }
  }

  cout<<ans<<'\n';

  return 0;
}
