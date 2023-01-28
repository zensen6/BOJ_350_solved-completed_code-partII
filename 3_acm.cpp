#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;

int n, ans = 0;
int arr[33][33];

int proc(int rl, int rh, int cl, int ch){
  int ret = 0;
  if(rl == rh){
    if(cl == ch){
      return ret;
    }else{
      int mid = (cl+ch)>>1;
      int ans1 = 0, ans2 = 0;
      for(int j = cl; j <= mid; j++) ans2= max(ans2,arr[rl][j]);
      for(int j = mid+1; j <= ch; j++) ans1 = max(ans1,arr[rl][j]);
      ret = max(proc(rl, rh, cl, mid)+ans1, proc(rl, rh, mid+1, ch)+ans2);
      return ret;
    }
  }else if(cl == ch){
    if(rl == rh){
      return ret;
    }else{
      int mid = (rl+rh)>>1;
      int ans1 = 0, ans2 = 0;
      for(int j = rl; j <= mid; j++) ans2=max(ans2,arr[j][cl]);
      for(int j = mid+1; j <= rh; j++) ans1=max(ans1,arr[j][cl]);
      ret = max(proc(rl,mid,cl,ch)+ans1, proc(mid+1,rh,cl,ch)+ans2);
      return ret;
    }
  }
  int rmid = (rl + rh)>>1;
  int cmid = (cl + ch)>>1;
  int ans1 =0, ans2 = 0, ans3 = 0,ans4 = 0;
  for(int i = rl; i <= rh; i++){
    for(int j = cl; j <= cmid; j++){
      ans1 = max(ans1, arr[i][j]);
    }
  }
  for(int i = rl; i <= rh; i++){
    for(int j = cmid+1; j <= ch; j++){
      ans2 = max(ans2, arr[i][j]);
    }
  }
  for(int i = rl; i <= rmid; i++){
    for(int j = cl; j <= ch; j++){
      ans3 = max(ans3, arr[i][j]);
    }
  }
  for(int i = rmid+1; i <= rh; i++){
    for(int j = cl; j <= ch; j++){
      ans4 = max(ans4, arr[i][j]);
    }
  }
  int ret1 = max(proc(rl,rh,cmid+1,ch)+ans1, proc(rl,rh,cl,cmid)+ans2);
  int ret2 = max(proc(rmid+1,rh,cl,ch)+ans3, proc(rl,rmid,cl,ch)+ans4);
  ret = max(ret1,ret2);
  return ret;

}

int main(){

  cin>>n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin>>arr[i][j];
    }
  }
  cout<<proc(1,n,1,n)<<'\n';
  return 0;
}
