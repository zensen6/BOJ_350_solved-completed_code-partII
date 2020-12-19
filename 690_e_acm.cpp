#include<bits/stdc++.h>
#define MOD 1000000007LL;
using namespace std;

int main(){

  int t,n,x;
  cin>>t;
  while(t--){
    cin>>n;
    vector<int> a;
    for(int i = 1; i <= n; i++){
      cin>>x;
      a.push_back(x);
    }
    long long s_ = 0;
    if(n<3) cout<<0<<'\n';

    else{
      sort(a.begin(),a.end());
      for(int i = 0; i < n-2; i++){
        int pivot = a[i];

        int r = upper_bound(a.begin(),a.end(),pivot+2) - a.begin() -1;
        if(r <= i+1){
          continue;
        }else if(a[r] > pivot + 2){
          continue;
        }
        //cout<<r<<'\n';
        s_ += ((r-i)*(r-i-1LL))/2LL;
        s_ %= MOD;
        //s_ += (((r-i-1)*(r-i))/2 - ((l-i-2)*(l-i-1))/2);

      }
      cout<<s_<<'\n';

    }

  }



  return 0;
}
