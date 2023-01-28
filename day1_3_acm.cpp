#include<bits/stdc++.h>
#define MOD 1000000007LL

typedef long long ll;

using namespace std;

string x;
string x_;
ll d[10001][16];

ll proc(int index, int state){
    ll &ret = d[index][state];
    if(index == x_.length()-1){
        d[index][state] = 1LL;
        ret = d[index][state];
        return ret;
    }
    if(ret != -1LL) return ret;
    ret = 0;
    int p = int(x_[index+1]-'0');
    int newstate = (1<<p);
    for(int i = 0; i <= 15 - newstate; i++){
        int ns = newstate + i;
        if(((1<<p)&ns) && (ns&state)){
            //cout<<index<<" "<<ns<<'\n';
            ret += proc(index+1,ns);
            ret %= MOD;
        }
    }
    ret %= MOD;
    return ret;
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
        x_ = "";
        memset(d,-1LL,sizeof(d));
        cin>>x;
        for(auto &p:x){
            if(p=='A') x_ += '0';
            else if(p=='B') x_ += '1';
            else if(p=='C') x_ += '2';
            else if(p=='D') x_ += '3';
        }
        int state = 0;
        state |= 1;
        int p = (1<<int(x_[0]-'0'));
        state |= p;
        ll ans = 0;
        for(int i = 0; i <= 15-state; i++){
            int ns = state + i;
            if((state&ns) == state){
                ans += proc(0,ns);
                //cout<<ns<<" "<<ans<<'\n';
                ans %= MOD;
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<'\n';
        //cout<<d[0][1]<<'\n'; -> 64나와야 하는데 8
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}