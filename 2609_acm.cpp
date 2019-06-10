#include <iostream>
#define SWAP(X,Y,Z) ((Z=X),(X=Y),(Y=Z))
using namespace std;

int GCD(int N, int M){
	
	
	if(N%M!=0) return GCD(M,N%M);
	else if(N%M==0 || M==1) return M;
	
}

int LCD(int N, int M){
	 int r = GCD(N,M);
	return (N/r) * M;
	
	
}


int main(){
	
	int  N,M,T;
	cin>>N>>M;
	if(N<M){
		SWAP(N,M,T);
	}
	cout<<GCD(N,M)<<'\n';
	cout<<LCD(N,M)<<'\n';
	
	
}
