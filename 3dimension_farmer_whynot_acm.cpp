#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,c1,c2,x;
vector<int> cow, horse;


pair<int,int> proc(){
    int f = 200000001,s=0;
    for(int i=0;i<n;i++){
        int c = cow[i];
        int near1 = lower_bound(horse.begin(),horse.end(),c) - horse.begin();
        if(near1 < horse.size()){ 
            int dist1 = horse[near1] - c;
            if(dist1 < f){
                f = dist1;
                s = 1;
            }else if(dist1 == f){
                s++;
            }
        }
        if(near1 == 0) continue;
        int dist2 = c - horse[near1-1];
        if(dist2 < f){
            f = dist2;
            s = 1;
        }else if(dist2 == f){
            s++;
        }
    }
    return {f,s};
}


int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
        cow.clear();
        horse.clear();
        cin>>n>>m;
        cin>>c1>>c2;
        for(int i=0;i<n;i++){
            cin>>x;
            cow.push_back(x);
        }
        sort(cow.begin(),cow.end());
        for(int i=0;i<m;i++){
            cin>>x;
            horse.push_back(x);
        }
        sort(horse.begin(),horse.end());
        auto ans = proc();
        cout<<"#"<<test_case<<" "<<ans.first+abs(c2-c1)<<" "<<ans.second<<'\n'; 
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}