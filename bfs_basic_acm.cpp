#include <stdio.h>

using namespace std;


extern void bfs_init(int N, int map[10][10]);
extern int bfs(int x1, int y1, int x2, int y2);

static int test_bfs() {
	int N;
	int map[10][10];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	bfs_init(N, map);
	int M;
	int score = 100;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = bfs(x1, y1, x2, y2);
		int dist;
		scanf("%d", &dist);
		if (result != dist) score = 0;
	}
	return score;
}

int main() {
	setbuf(stdout, NULL);

	printf("#total score : %d\n", test_bfs());

	return 0;
}

#define MAXVALUE 10001 

bool check[11][11];

template<class T> class Queue
{
public:
	int front;
	int rear;
	int size;
	T *values;

	Queue()
	{
		size = MAXVALUE;
		values = new T[size];
		front = 0;
		rear = 0;
	}
	~Queue()
	{
		delete[] values;
	}

	void push(T value)
	{
		if(!isFull())
		{
			values[rear] = value;
			rear = (rear + 1) % size;
		}
	}

	void pop()
	{
		if(!empty())
			front = (front + 1) % size;
	}

	bool empty()
	{
		if(rear == front)
			return true;
		else 
			return false;
	}

	bool isFull()
	{
		if((rear + 1) % size == front) 
			return true;
		else 
			return false;
	}
};

int dy[4] = {-1,0,0,1}, dx[4] = {0,-1,1,0};
int n;

bool inrange(int y,int x){
    return y>=0&&y<n&&x>=0&&x<n;
}

void bfs_init(int map_size, int map[10][10]) {
    n = map_size;
    for(int i=0;i<11;i++){
     for(int j=0;j<11;j++){
         check[i][j] = false;
     }
    }
    return;
}
int bfs(int x1, int y1, int x2, int y2) {
    Queue<pair<int,int>> q;
    q.push({y1,x1});
    check[y1][x1] = true;
    while(!q.empty()){
      auto f = q.front();
        q.pop();
        int y=f.first, x=f.second;
        for(int dir=0;dir<4;dir++){
           int ny=y+dy[dir], dx=x+dx[dir];   
           if(inrange(ny,nx)){
             if(!check[ny][nx]&&){
                  
                 
             }
               
           }
        }
    }
    
    return 0;
}