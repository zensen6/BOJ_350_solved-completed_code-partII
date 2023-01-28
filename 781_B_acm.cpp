#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;
ll n;
ll gcd(ll a, ll b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a*b/gcd(a,b);
}


map<int,int> m_;
int main(){


  cin>>t;
  while(t--){
    cin>>n;
    vector<int> arr(n);
    m_.clear();
    for(int i=0;i<n;i++){
      cin>>arr[i];
      m_[arr[i]]++;
    }
    int M=0,k=0;
    map<int,int>::iterator it;
    for(it=m_.begin();it!=m_.end();it++){
      M = max(M,it->second);
    }
    k = n-M;
    if(k==0) cout<<0<<'\n';
    else if(M>=k) cout<<1+k<<'\n';
    else{
      for(int i=1;i<20;i++){
        if(M*(pow(2,i)-1) < k && k <= M*(pow(2,i+1)-1)){
          cout<<i+1+k<<'\n';
          break;
        }
      }
    }
    int c=0;


  }



  return 0;
}
