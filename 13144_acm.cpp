#include<bits/stdc++.h>
using namespace std;

bool check[100001];

typedef long long ll;

ll ap(int x){
  return (x*(x+1LL))/2LL;
}

ll ans = 0;

int main(){

  memset(check,false,sizeof(check));
  int n;

  cin>>n;
  vector<int>arr(n,0);
  for(int i = 0 ; i < n; i++){
    cin>>arr[i];
  }
  int l = 0, r = 0, saved_r=-1;
  check[arr[l]] = true;
  while(l<=r && l<n){
    if(r+1<n && !check[arr[r+1]]){
      check[arr[r+1]] = true;
      r++;
      if(r==n-1){
        ans += ap(r-l+1);
        ans -= ap(saved_r-l+1);

        //cout<<r<<" "<<l<<" "<<saved_r<<'\n';
        break;
      }
    }else if(r+1<n && check[arr[r+1]]){
      ans += ap(r-l+1);
      ans -= ap(saved_r-l+1);
      saved_r = r;
      //cout<<ans<<'\n';
      //cout<<r<<" "<<l<<" "<<saved_r<<'\n';
      while(check[arr[r+1]]){
        check[arr[l]] = false;
        l++;
        if(l>r){
          saved_r = r;
          r = l;
          check[arr[r]] = true;
          break;
        }
      }
    }else if(r==n-1){
      ans += ap(r-l+1);
      ans -= ap(saved_r-l+1);
      break;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
