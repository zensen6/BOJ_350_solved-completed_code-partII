#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
int d[3002][101][101][2];
int n, m;
int arr[3002];
vector<int> M;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i];
        cin>>m;
        int x;
        for(int i=0;i<m;i++){
            cin>>x;
            M.push_back(x);
        }
        sort(M.begin(),M.end());
        memset(d,0,sizeof(d));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=m-j;k++){
                    for(int l=0;l<=1;l++){ // l=0: i번째 있는거 이미먹음
                        if(l==0){
                            if(i==0){
                                if(k>0) d[0][j][k][0] =  max(d[0][j][k][0], d[0][j][k-1][1] + M[m-k]);
                            }else{
                                d[i][j][k][0] = max(d[i][j][k][0],d[i-1][j][k][1] + arr[i]);
                                if(j>0) d[i][j][k][0] = max(d[i][j][k][0], d[i-1][j-1][k][0] + arr[i]);
                                if(k>0){
                                    d[i][j][k][0] = max(d[i][j][k][0], d[i-1][j][k-1][1] + M[m-k]);
                                    d[i][j][k][0] = max(d[i][j][k][0], d[i][j][k-1][1] + M[m-k]);
                                }
                            }
                        }else{
                            if(i==0){
                                if(j>0){
                                    d[0][j][k][1] = max(d[0][j][k][1], d[0][j-1][k][0]);
                                    d[0][j][k][1] = max(d[0][j][k][1], d[0][j-1][k][1]);
                                }
                            }else{
                                d[i][j][k][1] = max(d[i][j][k][1], d[i-1][j][k][0]);
                                if(k>=1) d[i][j][k][1] = max(d[i][j][k][1], d[i-1][j][k-1][1] + M[m-k]);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int j=0;j<=m;j++){
            for(int k=0;k<=m-j;k++){
                for(int l=0;l<=1;l++){
                    ans = max(ans, d[n][j][k][l]);
                }
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}