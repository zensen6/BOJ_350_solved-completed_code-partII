#include<bits/stdc++.h>
using namespace std;

int main(){

  int t,n,x;
  cin>>t;
  while(t--){

    cin>>n;
    vector<vector<int>> arr(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cin>>arr[i][j];
      }
    }
    vector<pair<pair<int,int>,pair<int,int>>> pos[10];
    for(int num=0; num < 10; num++){
      int mx=n+1,Mx=0,my=n+1,My=0;
      for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
          if(arr[i][j] == num){
            mx=min(mx,j);
            Mx=max(Mx,j);
            my=min(my,i);
            My=max(My,i);
          }
        }
      }
      pos[num] = {{my,mx},{My,Mx}};
    }


  }



  return 0;
}
