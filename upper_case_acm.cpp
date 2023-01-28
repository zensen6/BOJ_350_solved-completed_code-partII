#include<bits/stdc++.h>
using namespace std;

int n;


int main(){

  int arr[9] = {0,1,1,2,3,4,5,6,9};
  cin>>n;
  cout<<binary_search(arr,arr+9,n)<<'\n';
  return 0;
}
