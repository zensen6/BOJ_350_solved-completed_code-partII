#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int a[30][30];
int d[30][30];
int N;
int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};
	
	
bool inrange(int y, int x){
	
	if(x<0 || x>N || y<0 || y>N) return false;
	else return true;
	
}
	
int	bfs(int y, int x, int cnt, int num){
	
	queue< pair<int,int> > q;
	q.push(make_pair(y,x));
	d[y][x]=num;
	++cnt;
	while(!q.empty()){
		
		int fy = q.front().first; 
		int fx = q.front().second;
		q.pop();	
		for (int i=0; i<4;i++){			
			int nx = fx+dx[i];
			int ny = fy+dy[i];
			
			if(inrange(ny,nx) && a[ny][nx]==1 && d[ny][nx]==0){
		
				q.push(make_pair(ny,nx));
				d[ny][nx]=num;
				cnt++;	
			}
			
		}
	}
	
	return cnt;
} 



int main(){
	
	
	scanf("%d",&N);
	int arr[625]={0};
	int c=0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%1d",&a[i][j]);
		}
	}		
	
	int cnt=0;
	int num=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(a[i][j]==1 && d[i][j]==0){	
				arr[c++] = bfs(i,j,cnt,++num);
				cnt = 0;
			}
		}
	}
	
	int len=0;
	while(arr[len++]!=0){}
	sort(arr,arr+len-1);
	printf("%d\n",num);
	for(int i=0;i<len-1;i++){
		printf("%d\n",arr[i]);
	}
	
	return 0;
}

