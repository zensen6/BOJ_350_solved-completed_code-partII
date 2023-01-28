#include<bits/stdc++.h>
#define MAX 1000000001
#define MIN -1000000001
using namespace std;

int n;
vector<int> arr,d;
set<int> s;
int ans = MAX, mini = MAX, maxi = MIN;

int main(){
  cin>>n;
    arr = vector<int>(n,0);
  for(int i = 0; i < n; i++){
    cin>>arr[i];
    if(i!=0){
      int f = arr[i] - arr[i-1];
      d.push_back(f);
      s.insert(f);
      mini = min(f,mini);
      maxi = max(f,maxi);
    }
  }
  if(maxi - mini > 4){
    cout<<-1<<'\n';
    return 0;
  }else if(n==1){
    cout<<0<<'\n';
    return 0;
  }
  for(int p=mini;p<=maxi;p++){
    for(int a0=arr[0]-1;a0<=arr[0]+1;a0++){
      bool able=true;
      int c = a0==arr[0]?0:1,len=arr.size();
      vector<int>arr_copy = arr;
      arr_copy[0] = a0;
      for(int i=1;i<len;i++){
        if(arr_copy[i]>arr_copy[i-1]+p+1 || arr_copy[i]<arr_copy[i-1]+p-1){
          able=false;
          break;
        }
        if(arr_copy[i]==arr_copy[i-1]+p+1){
          arr_copy[i]--;
          c++;
        }else if(arr_copy[i]==arr_copy[i-1]+p-1){
          arr_copy[i]++;
          c++;
        }
      }
      if(able) ans=min(ans,c);
    }
  }
  ans=ans==MAX?-1:ans;
  cout<<ans<<'\n';
  return 0;
}
