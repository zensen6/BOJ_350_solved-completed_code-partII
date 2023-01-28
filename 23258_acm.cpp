#include<iostream>
#include<memory.h>
#define INF 1000000001
using namespace std;

int d[302][301][301],arr[301][301];
int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

	int c,n,q,s,e;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==0&&i!=j) arr[i][j]=INF;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[k][i][j]=INF;
				d[k][i][j]=min(d[k][i][j],arr[i][j]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(arr[i][k]+arr[k][j] < d[k][i][j] && k!=i&&k!=j){
					d[k][i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
  for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
  
  for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<d[k][i][j]<<" ";
			}
      cout<<'\n';
		}
    cout<<'\n';
	}

	while(q--){
		cin>>c>>s>>e;
    if(c==n+1) cout<<arr[s][e]<<'\n';
		else{
      int ans = INF;
      for(int i = 1; i < c; i++){
        ans = min(ans,d[i][s][e]);
      }
      if(ans >= INF) cout<<-1<<'\n';
      else cout<<ans<<'\n';
    }
	}




	return 0;
}
