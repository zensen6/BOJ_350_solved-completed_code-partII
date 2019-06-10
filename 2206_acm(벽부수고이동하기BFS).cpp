#include<cstdio>
#include<queue>
using namespace std;


int map[1001][1001];
bool check[1001][1001]={false};
int price[1001][1001];

int dy[2]={0,1};
int dx[2]={1,0};

bool inrange(int N, int M, int y, int x){
	
	if(y<=0||y>=N||x<=0||x>=M) return false;
	return true;
	
}


void bfs(int N, int M, int y, int x, int once){
	
	queue< pair<int,int> >q;
	q.push(make_pair(y,x));
	check[y][x]=true;
	price[y][x]=1;
	while(!q.empty()){
		
		int fy = q.front().first;
		int fx = q.front().second;
		int ny,nx;
		q.pop();
		for(int i=0;i<=1;i++){
			
			ny=fy+dy[i];
			nx=fx+dx[i];
			if(inrange(N,M,ny,nx) && !check[ny][nx]){
				
				if(map[ny][nx]==0){
						
					check[ny][nx]=true;
					price[ny][nx]=price[fy][fx]+1;
					q.push(make_pair(ny,nx));
					
				}
				else{
					if(once==1){
						check[ny][nx]=true;	
						price[ny][nx]=price[fy][fx]+1;
						q.push(make_pair(ny,nx));
					}
					else{
						price[ny][nx]=-1;
						
					}
					
				}
			}
			
		}
		once=0;		
		
		
	}
	
	
}

int main(){
	
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	bfs(N,M,1,1,1);
	printf("%d\n",price[N][M]);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			printf("%d ",price[i][j]);
		}
		printf("\n");
	}
	
	
}
