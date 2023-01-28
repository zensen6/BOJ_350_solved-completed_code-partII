#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000000000
using namespace std;

int n,v;
int d[1001][1001];
vector<int> arr;
int main(){

	cin>>n>>v;
	arr=vector<int> (n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}


		for(int j=0;j<1001;j++){
			for(int k=0;k<1001;k++){
				d[j][k]=MAX;
			}
		}
	d[arr[0]][arr[0]] = 1;

	for(int i=1;i<n;i++){
		for(int m=0;m<1001;m++){
			for(int M=0;M<1001;M++){
				if(i==1){
					if(d[m][M]!=MAX){
						d[min(m,arr[1])][max(M,arr[1])]=2;
					}
				}else{
					if(d[m][M]!=MAX){
						d[min(m,arr[i])][max(M,arr[i])] = min(d[min(m,arr[i])][max(M,arr[i])],d[m][M] + ((M-m) >= v ? 0:1));
					}
					if(d[i-1][m][M]!=MAX){
						d[i][min(m,arr[i])][max(M,arr[i])]= min(d[i][min(m,arr[i])][max(M,arr[i])],d[i-1][m][M] + ((M-m) >= v ? 0:1));
					}

				}
			}
		}
	}
	int ans =MAX;
	if(n==1) cout<<1<<'\n';
	else{
		for(int i=1;i<n;i++){
			for(int j=0;j<1001;j++){
				for(int k=0;k<1001;k++){
					if(abs(j-k)>=v && d[i][j][k]!=MAX){
						ans=min(ans,d[i][j][k]);
					}
				}
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}
