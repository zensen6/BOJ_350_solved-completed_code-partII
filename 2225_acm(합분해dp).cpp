#include <iostream>
using namespace std;

const long long MAX=1000000000LL;


long long int D[201][201]={0};
 
long long int go(int N, int K){
	
	for(int k=0;k<=K;k++) D[0][k]=1;
	for(int i=1;i<=N;i++){
		D[i][0]=0;
		D[i][1]=1;
	}
	
	for(int i=1;i<=N;i++){
		for(int k=2;k<=K;k++){
			for(int j=0;j<=i;j++){
				
				D[i][k] +=D[i-j][k-1];
				D[i][k] %=MAX;
				
			}
	
		}
		
	}
	
	//if(N==0 && K>1) return D[0][K] = 0;
	//if(N==0 && K==1) return D[0][K] = 1;
	//else if(K==1) return D[N][1] = 1;	
	//for(int i=0;i<=N;i++){
		
	//	sum=(sum+go(N-i,K-1)%MAX)%MAX;
		
	//}
	
	return D[N][K];
	
}

int main(){
	
	int N,K;
	cin>>N>>K;
	go(N,K);
	cout<<D[N][K]<<'\n';
	
	
	return 0;
}
