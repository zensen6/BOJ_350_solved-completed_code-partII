#include<stdio.h>
#include<stdlib.h>

int mul(int** arr1, int** arr2, int i, int j, int size){
	
	int sum=0;
	for(int h=0;h<size;h++){
		
		sum+=arr1[i][h]*arr2[h][j];
		
		
	}
	
	return sum;
	
}


int main(){
	
	int N,M;
	int K;
	int** arr1;
	scanf("%d %d",&N, &M);
	arr1=(int**)malloc(N*sizeof(int*));
	for(int i=0;i<N;i++){
		arr1[i] = (int*)malloc(M*sizeof(int));
		
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&arr1[i][j]);
		}
	}
	scanf("%d %d",&M, &K);
	int** arr2=(int**)malloc(M*sizeof(int*));
	for(int i=0;i<M;i++){
		arr2[i] = (int*)malloc(K*sizeof(int));
		
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<K;j++){
			scanf("%d",&arr2[i][j]);
		}
	}
	
	int **arr3=(int**)malloc(N*sizeof(int*));
	for(int i=0;i<N;i++){
		arr3[i] = (int*)malloc(K*sizeof(int));
		
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			
			arr3[i][j] = mul(arr1,arr2,i,j,M);
			
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			printf("%d ",arr3[i][j]);
		}
		printf("\n");
	}
	
	for(int i=0;i<N;i++) free(arr1[i]);
	free(arr1);
	for(int i=0;i<M;i++) free(arr2[i]);
	free(arr2);
	for(int i=0;i<N;i++) free(arr3[i]);
	free(arr3);
	
	return 0;	
}
