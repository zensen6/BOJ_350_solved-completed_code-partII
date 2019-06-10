#include<iostream>
using namespace std;

long long d[101][101];




int main(){
	
	int n,m;
	cin>>n>>m;
	d[1][0] = d[1][1] = 1;
	
	for(int i=1;i<=100;i++){
		d[i][i] = d[i][0] = 1;
	}
	
	for(int i=2;i<=100;i++){
		for(int j=1;j<=i-1;j++){
			
			d[i][j] = d[i-1][j-1] + d[i-1][j];	
			
		}
		
	}
	cout<<d[n][m]<<'\n';
	
	
	return 0;
}
