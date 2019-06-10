#include<iostream>
#include<memory.h>
	
using namespace std;
	
int arr[9][9];
bool check[9][9] = {false};
int cnt = 0;
bool stop = false;

bool yescheck(int y, int x, int n){
	bool checkx[9];
	bool checky[9];
	bool checkcube[9];
	
	memset(checkx,false,sizeof(checkx));
	memset(checky,false,sizeof(checky));
	memset(checkcube,false,sizeof(checkcube));
	
	int cubey = y/3;
	int cubex = x/3;
	
	for(int i=0;i<9;i++){
		
		if(i==x) continue;
		checkx[arr[y][i]] = true;
		
	}
	for(int j=0;j<9;j++){
		
		if(j==y) continue;
		checky[arr[j][x]] = true;
		
	}
	for(int i=3*cubey;i<3*cubey+3;i++){
		for(int j=3*cubex;j<3*cubex+3;j++){
			
			if(i==y && j==x) continue;
			checkcube[arr[i][j]] = true;
			
		}
		
	}
	if(!checkx[n] && !checky[n] && !checkcube[n]) return true;
	else{
		return false;
	}
}
	

bool go(int zero){

	if(zero==0){
		
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
			
				cout<<arr[i][j]<<' ';
				
			}
			cout<<'\n';
		}	

		return true;	
		
	} 
	
	else{
	
		int i=0,j=0;
		bool taken = false;
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				
				if(arr[i][j]==0){
					taken = true;
					break;
				}
				
			}
			if(taken) break;
		}
		
		for(int k=1;k<=9;k++){
			
			arr[i][j] = k;
			if(yescheck(i,j,k)){
				
				if(go(zero-1)){
					
					return true;
					
				}
				
			}
			arr[i][j] = 0;
			
		}
		return false;
	
	}
	
}	
		
	
	
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int zero = 0;
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>arr[i][j];
			if(arr[i][j] == 0){
				
				zero +=1;
			}		
		}
	}		
	
	go(zero);
	
	return 0;
	
}
