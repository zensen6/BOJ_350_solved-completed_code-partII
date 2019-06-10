#include<cstdio>
#include<stdlib.h>

using namespace std;

int main(){
	
	int N,M,i,j,x,y;	
	scanf("%d %d",&N,&M);
	int** arr = (int**)malloc(N*sizeof(int*));
	for(int k=0;k<N;k++){
		arr[k] = (int*)malloc(M*sizeof(int));
	}
	int T;
	for(int k=0;k<N;k++){
		for(int j=0;j<M;j++){
			scanf("%d",&arr[k][j]);
		}
	}	
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		scanf("%d %d %d %d",&i,&j,&x,&y);
		int sum=0;	
		for(int k=i-1;k<=x-1;k++){
			for(int l=j-1;l<=y-1;l++){
				
				sum+=arr[k][l];
			}
		}
		printf("%d\n",sum);
	} 
	for(int i=0;i<N;i++) free(arr[i]);
	free(arr);
	return 0;
}
