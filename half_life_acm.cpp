#include<iostream>
#include<vector>


using namespace std;

int n,m,x;
vector<int> arr,W;


bool possible(int never_this_val){
    int p=0,i=0;
    while(p<n && i<m){
        while(arr[p]>=never_this_val){
            p++;
            if(p==n) return i==m;
        }
        int l=0;
        while(arr[p]<never_this_val){
            p++;
            l++;
            if(l==W[i]){
                l=0;
                i++;
            }
            if(i==m) return true;
            if(p==n) return i==m;
        }
        
    }
    return i==m;
}

int proc(){
        int ans=200000;
        int lo = 1, hi = 200000;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(possible(mid)){ // possible under mid value
                ans = min(ans,mid-1);
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }

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
        arr.clear();
        W.clear();
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>x;
            arr.push_back(x);
        }
        for(int i=0;i<m;i++){
            cin>>x;
            W.push_back(x);
        }
        cout<<"#"<<test_case<<" "<<proc()<<'\n';
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}