#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> m;
int main(){

  int n,c=0;
  cin>>n;
  vector<ll> arr(n,0);
  for(int i = 0 ; i < n; i++){
    cin>>arr[i];
    m[arr[i]]++;
  }
    sort(arr.begin(),arr.end());
    for(int pivot = 0; pivot < n; pivot++){
      bool done = false;
      for(int l = 0 ; l < n; l++){
        if(l == pivot) continue;
        int k = lower_bound(arr.begin(),arr.end(),arr[pivot] - arr[l]) - arr.begin();
        if(k!=n){
          if(arr[pivot] == 0 && arr[l] == 0 && arr[k] == 0 && m[0] <= 2){
            continue;
          }
          else if(arr[pivot] - arr[l] == arr[k] && (m[arr[k]] >= 2 || l!=k) && (m[arr[k]] >= 2 || k!=pivot)){
            done = true;
            break;
          }
        }
      }
      if(done){
        c++;
      }
    }
    cout<<c<<'\n';
  
  return 0;
}
