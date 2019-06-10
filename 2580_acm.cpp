#include<cstdio>

bool check[26] = {false};
int row,col;
int max0=1;
int ans=1;

int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};

bool inrange(int y, int x){
	
	if(y<0 || x<0 || y>=row || x>=col){
		return false;
	}
	return true;
}

void go(char arr[20][20], int y, int x){

	check[arr[y][x]-'A'] = true;
	bool yes = false;
	int fy,fx;
	for(int i=0;i<4;i++){
		fy=y+dy[i];
		fx=x+dx[i];
		if(inrange(fy,fx) && !check[arr[fy][fx]-'A']) yes=true;
	}
	if(!yes){
		if(ans>=max0) max0=ans;
		return;
	} //impossible
	for(int i=0;i<4;i++){
		fy=y+dy[i];
		fx=x+dx[i];
		if(inrange(fy,fx) && !check[arr[fy][fx]-'A']){
			
			check[arr[fy][fx]-'A'] = true;
			ans+=1;
			go(arr, fy, fx);
			ans-=1;
			check[arr[fy][fx]-'A'] = false;
			
			
		}
			
	}
}

int main(){
	
	char arr[20][20];

	scanf("%d %d",&row,&col);
	getchar();
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			scanf("%1c",&arr[i][j]);
		}
		getchar();
	}

	go(arr,0,0);
	printf("%d\n",max0);

	return 0;
	
}
