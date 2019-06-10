#include <cstdio>
#include <queue>

using namespace std;

int arr[100][100];
int N,M;
bool check[100][100] = {false};

int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};


bool inrange(int y, int x){
	
	if(y<0||x<0||y>=N||x>=M||arr[y][x]==0) return false;
	else return true;
}


void bfs(int y,int x){
	
	
	queue< pair<int,int> > q;
	q.push(make_pair(y,x));
	check[y][x] = true;
	arr[y][x]=1;
	
	while(!q.empty()){
		
		y=q.front().first;
		x=q.front().second;
		q.pop();
		int nx, ny;
		for(int i=0;i<4;i++){
			
			ny = y+dy[i];
			nx = x+dx[i];
			if(inrange(ny,nx) && !check[ny][nx] && arr[ny][nx]==1){
				
				check[ny][nx]=true;
				arr[ny][nx]=arr[y][x]+1;
				q.push(make_pair(ny,nx));	
			}
		}
	}
}


int main(){
	
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){	
			scanf("%1d",&arr[i][j]);	
		}
	}
	bfs(0,0);
	
	printf("%d\n",arr[N-1][M-1]);
	
	return 0;
	
	
}
