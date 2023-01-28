#include<bits/stdc++.h>
using namespace std;

int n,arr[401][810],l[401][810];

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc=1;
  while(1){
    cin>>n;
    if(!n) break;
    memset(arr,0,sizeof(arr));
    int c=1,ans=-1000000000;
    for(int i=0;i<n;i++){
        for(int j=0;j<(2*i+1);j++){
          cin>>arr[i][j];
          if(j==0) l[i][0]=arr[i][0];
          else{
            l[i][j]=l[i][j-1]+arr[i][j];
          }
          ans=max(ans,arr[i][j]);
        }
    }
    for(int y=0;y<=n-1;y++){
      for(int x=0;x<=2*y;x+=2){
        int psum=0;
        for(int h=0;h<=n-1-y;h++){
          psum += (l[y+h][2*h+x]-(x==0?0:l[y+h][x-1]));
          ans=max(ans,psum);
        }
      }
    }

    for(int height=2;height<=(n/2);height++){
      for(int y=2*height-1;y<=n-1;y++){
        for(int x=2*height-1;x<=2*y-2*height+1;x+=2){
          int psum=0;
          for(int h=0;h<height;h++){
            psum += (l[y-h][x]-l[y-h][x-2*h-1]);
          }
          ans=max(ans,psum);
        }
      }
    }
    cout<<tc<<". "<<ans<<'\n';
    tc++;
  }


  return 0;
}
