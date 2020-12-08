#include<stdio.h>
#define SWAP(X,Y,Z) ((Z=X),(X=Y),(Y=Z))

int main(){

	int arr[8][2];
	int x,sum=0;
	for(int i=0;i<8;i++){

		scanf("%d",&arr[i][0]);
		arr[i][1] = i+1;
	}

	int t, min;
	for(int i=0;i<8-1;i++){
		min = i;
		for(int j=i+1;j<8;j++){

			if(arr[min][0] > arr[j][0]) min = j;

		}
		SWAP(arr[min][0],arr[i][0],t);
		SWAP(arr[min][1],arr[i][1],t);

	}
	for(int k=3;k<8;k++){

		sum+=arr[k][0];

	}
	for(int i=3;i<8-1;i++){
		min = i;
		for(int j=i+1;j<8;j++){

			if(arr[min][1] > arr[j][1]) min = j;


		}
		SWAP(arr[min][1],arr[i][1],t);

	}
	printf("%d\n",sum);
	for(int k=3;k<8;k++){

		printf("%d ",arr[k][1]);

	}

	return 0;

}
