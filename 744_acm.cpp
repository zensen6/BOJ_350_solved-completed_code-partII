#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool isPrime[10001];

int main(){

  for(int i = 1; i <= 10000; i++) isPrime[i] = true;
  ll n;
  cin>>n;
  isPrime[1] = false;
  isPrime[2] = true;
  for(int i = 2; i*i <= 10000; i++){
    for(int j = i*i; j <= 10000; j+=i){
      if(isPrime[i]) isPrime[j] = false;
    }
  }
  vector<int> v;
  for(int i = 2; i <= 10000; i++) if(isPrime[i]) v.push_back(i);
  int len = v.size();
  for(int i = 0; i < len-1; i++){
    if(v[i]*v[i+1] > n){
      cout<<v[i]*v[i+1]<<'\n';
      return 0;
    }
  }
`
  return 0;
}
