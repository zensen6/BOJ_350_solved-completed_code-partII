#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, alpha[10];
bool check[10];
int match[10];
vector<string> arr;
vector<int> num;
string x;
ll ans = 0;

ll ten[12] = {
  1LL,
  10LL,
  100LL,
  1000LL,
  10000LL,
  100000LL,
  1000000LL,
  10000000LL,
  100000000LL,
  1000000000LL,
  10000000000LL,
  100000000000LL
};

void proc(int index){
  if(index == 10){
    ll s=0;
    for(int i=0;i<n;i++){
      int len=arr[i].length();
      for(int j=0;j<len;j++){
        s+=1LL*match[(arr[i][j]-'A')]*ten[len-j-1];
      }
    }
    ans=max<ll>(ans,s);
    return;
  }
  for(int i=0;i<10;i++){
      if(index == 0 && alpha[i]){
        continue;
      }
      if(check[i]) continue;
      check[i] = true;
      match[i] = index; //match[alphabet] = number;
      proc(index+1);
      match[i] = -1;
      check[i] = false;
  }

}


int main(){

    memset(match,-1,sizeof(match));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
        alpha[int(x[0]-'A')]++;
    }
    for(int i=0;i<10;i++) num.push_back(i);
    proc(0);
    cout<<ans<<'\n';

    return 0;
}
