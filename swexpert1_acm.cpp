#include<iostream>
#include<vector>
#include<memory.h>
#include<queue>

using namespace std;

int arr[101][101];
bool check[101][101];
int ans = 1;
int s = 0;
int n;
int dy[4] = {-1,0,0,1}, dx[4] = {0,-1,1,0};

bool inrange(int y, int x){
    return y>=0&&y<n&&x>=0&&x<n;
}

void proc(int y, int x, int h){
    queue<pair<int,int> > q;
    q.push({y,x});
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        int yy = f.first, xx = f.second;
        for(int dir=0;dir<4;dir++){
            int ny = yy+dy[dir], nx = xx+dx[dir];
            if(inrange(ny,nx)){
                if(!check[ny][nx] && arr[ny][nx] > h){
                    check[ny][nx] = true;
                    q.push({ny,nx});
                }
            }
        }
    }
    return;
}



int main(int argc, char** argv){

    int test_case;
    int T;
    cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(arr,0,sizeof(arr));
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        for(int h=1; h<=100; h++){
            memset(check,false,sizeof(check));
            s=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(!check[i][j] && arr[i][j] > h){
                        proc(i,j,h);
                        s++;
                    }
                }
            }
            ans = max(ans,s);
        }
        cout<<"#"<<test_case<<" "<<ans<<'\n';

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.



}