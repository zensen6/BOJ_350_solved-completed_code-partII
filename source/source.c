//#define _CRT_SECURE_NO_WARNINGS // fscanf, fprintf 오류 해결
#include <stdio.h>
#include <stdlib.h>
#define LEN 101
#define MAX 10100

int entY=-1, entX=-1,top=-1, fY=-1,fX=-1,success=0, check[101][101];
int count = 0,j=0,col=0;
char temp[101] = {0x00,};
char arr[101][101];


void error(char* message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}
typedef struct point{
	int y,x;
}Point;

Point stack[MAX];

int push(Point pos){
	if(top == MAX) return 0;
	stack[++top] = pos;
	return 1;
}

int pops(){
	if(top==-1) return 0;
	top--;
	return 1;
}

int empty(){
	if(top==-1) return 1;
	return 0;
}

Point Top(){
	return stack[top];
}


int dy[4] = {-1,0,0,1}, dx[4] = {0,-1,1,0};

int inrange(int y, int x){
	return y>=0&&y<j&&x>=0&&x<col;
}

int proc(int y, int x){
	Point here,next;
	here.y = y, here.x=x;
	if(arr[y][x] == 'X'){
		success = 1;
		return 1;
	}
	for(int dir=0;dir<4;dir++){
		int ny = y+dy[dir], nx = x+dx[dir];
		if(inrange(ny,nx)){
			if(!check[ny][nx] && (arr[ny][nx] == '0' || arr[ny][nx] == 'X')){
				next.y = ny, next.x = nx;
				printf("(%d, %d) -> ",ny,nx);
				check[ny][nx] = 1;
				push(next);
				if(proc(ny,nx)) return 1;
			}
		} 
	}
	return 0;
}

int main(){


	FILE* output = NULL;
	FILE* input = fopen("input.txt", "rt"); // 입력 파일 읽기 전용 개방
	// 입력 파일 불러오기가 정상적으로 작동되었는지 확인
	if (input == NULL)
	{
		error("입력 파일 불러오기에 실패했습니다.");
	}

	// 두 다항식의 길이 계산
	while (fgets(temp, LEN, input)!=NULL) {
		int c=0;
		for(;temp[c]!='\0';c++){
			arr[j][c] = temp[c];
			if(arr[j][c] == 'E'){
				entY = j, entX = c;
			}else if(arr[j][c] == 'X'){
				fY = j, fX = c;
			}
			col = (c>col?c:col);
		} 
		j++;
	}
	printf("%d %d\n",j,col);
	fclose(input); // 입력 파일 닫기
	
	//
	/*
	for(int y=0;y<col;y++){
		for(int x=0;x<j;x++){
			printf("%c ",arr[y][x]);
		}
		printf("\n");
	}
	*/
	printf("시작 (%d, %d) -> ",entY, entX);
	proc(entY,entX);
	if(success) printf("성공\n");
	else printf("실패\n");

	FILE* OP = fopen("output.txt","wt");
	for(int i=0;i<j;i++){
		for(int k=0;k<col;k++){
			if(arr[i][k]=='0') arr[i][k]=' ';
			else if(arr[i][k]=='1') arr[i][k]='*';
		}
	}
	for(int i=0;i<j;i++){
		fputs(arr[i],OP);
	}
	putc('\n',OP);
	putc('\n',OP);
	fputs("탐색 경로\n",OP);

	while(!empty()){
		Point t = Top();
		pops();
		arr[t.y][t.x] = '.';
	}
	arr[fY][fX] = 'X';


	for(int i=0;i<j;i++){
		fputs(arr[i],OP);
	}
	fclose(OP);
	return 0;
}