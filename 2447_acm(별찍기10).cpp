#include<iostream>
using namespace std;

char arr[10000][10000];

void star10(int y_start, int x_start, int y_end, int x_end, int N, int c){
	
	if(c==5){
		for(int i=y_start;i<=y_end;i++){
			for(int j=x_start;j<=x_end;j++){	
				arr[i][j]=' ';
			}	
		}
		return;
	}
	
	else if(N==1){
		arr[y_start][x_start]='*';
		return;
	}
	c=1;
	for(int row=0;row<3;row++){
		for(int col=0;col<3;col++){
			int y_mid3 = N/3;
			int x_mid3 = N/3;	
			
			star10(y_start+row*y_mid3 , x_start+col*x_mid3, y_start+((row+1)*y_mid3)-1, x_start+((col+1)*x_mid3)-1,N/3,c++);	
			
		}
	}
	
}

int main(){
	
	int N;
	cin>>N;
	
	star10(1,1,N,N,N,1);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<arr[i][j];
			
		}
		cout<<"\n";
		
	}
	return 0;
}
