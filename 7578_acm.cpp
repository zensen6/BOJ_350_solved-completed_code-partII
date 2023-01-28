#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>

using namespace std;

int n;
vector<int> A,B;

int main(){

  cin>>n;
  A = vector<int>(n,0);
  B = vector<int>(n,0);
  for(int i = 0 ; i < n; i++) cin>>A[i];
  for(int i = 0 ; i < n; i++) cin>>B[i];
  

  return 0;
}
