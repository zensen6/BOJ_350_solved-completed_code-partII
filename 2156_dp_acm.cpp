#include <iostream>

using namespace std;

int arr[10000];
int d[10000][2];

int max0(int a, int b, int c){
	
	if(a>=b) return a>=c? a:c;
	else return b>=c? b:c;
		
}

int max(int a, int b, int c, int d){
	
	int r=max0(a,b,c);
	return r>=d? r:d;
	
}

int max2(int a, int b){
	
	return a<=b? b:a;
}

int dp(int N){
	
	d[0][0] = arr[0];
	d[1][1] = d[0][0]+arr[1];
	d[1][0] = arr[1];
	d[2][1] = d[1][0]+arr[2];
	d[2][0] = d[0][0]+arr[2];
			
	for(int i=4;i<=N;i++){
		
		d[i-1][1] = d[i-2][0]+arr[i-1]; 
		d[i-1][0] = max(d[i-3][0]+arr[i-1],d[i-3][1]+arr[i-1],d[i-4][0]+arr[i-1],d[i-4][1]+arr[i-1]);
		
	}/*
	else if(N>=4){
		
		if(c==1){
		
			return d[N-1][1] = d[N-2][0]+arr[N-1];
		
		}	
	
		if(c==0){
		
			return d[N-1][0] = max(dp(N-3,0)+arr[N-1],dp(N-3,1)+arr[N-1],dp(N-4,0)+arr[N-1],dp(N-4,1)+arr[N-1]);
		
		}	
		
		
	}
	*/
	int MAX=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=1;j++){
			if(MAX<=d[i][j]) MAX= d[i][j];
			
		}
		
	}
		
	return MAX;
}


int main(){
	
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		
		cin>>arr[i];
		
	}
	cout<<dp(N)<<'\n';
	
	
	
	
	return 0;
}
