#include<iostream>
using namespace std;

int d[301][301];

int go(int N,int M){
	
	d[1][1] = 0;
	//d[1][2] = 1;
	//d[2][1] = 1;
	d[2][2] = 3;
	
	for(int i=1;i<=N;i++) d[i][1] = i-1;
	for(int j=1;j<=M;j++) d[1][j] = j-1;
	int min = 9876543;
	for(int i=2;i<=N;i++){
		for(int j=2;j<=M;j++){
			min = 9876543;
			for(int row=1;row<i;row++){
				if(d[i-row][j]+d[row][j]+1<=min) min = d[i-row][j]+d[row][j]+1;
			}
			for(int col=1;col<j;col++){
				if(d[i][j-col]+d[i][col]+1<=min) min = d[i][j-col]+d[i][col]+1;
			}
			d[i][j] = min;
			
		}	
	}
	
	return d[N][M];
	
}


int main(){
	
	int N,M;
	cin>>N>>M;	
	cout<<go(N,M)<<'\n';
	return 0;
}
