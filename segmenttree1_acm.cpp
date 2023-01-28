/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#define INF 1000000001

using namespace std;

typedef long long ll;

int n,q,c,x,idx,l,r;

int node[300030], node2[300030];
int arr[100010];


struct SegmentTree{
    void init(int start, int end, int node_index){
        if(start == end){
            node[node_index] = arr[start];
            node2[node_index] = arr[start];
            return;
        }
        int mid = (start+end)>>1;
        init(start,mid,node_index*2);
        init(mid+1,end,1+node_index*2);
        node[node_index] = min(node[node_index*2],node[1+node_index*2]);
        node2[node_index] = max(node2[node_index*2],node2[1+node_index*2]);
        return;
    }
    void change(int start, int end, int node_index, int index){
        if(end < index || start > index) return;
        else if(start == end){
            node[node_index] = arr[index];
            node2[node_index] = arr[index];
            return;
        }
        int mid = (start + end)>>1;
        change(start, mid, node_index*2, index);
        change(mid+1, end, 1+node_index*2, index);
        node[node_index] = min(node[node_index*2], node[1+node_index*2]);
        node2[node_index] = max(node2[node_index*2], node2[1+node_index*2]);
        return;
    }

    pair<int,int> search(int start, int end, int node_index, int l, int r){
        if(end < l || start > r) return {INF,-1};
        else if(l <= start && end <= r) return {node[node_index], node2[node_index]};
        int mid = (start + end)>>1;
        pair<int,int> left = search(start, mid, node_index*2, l, r);
        pair<int,int> right = search(mid+1, end, 1+node_index*2, l, r);
        return {min(left.first, right.first), max(left.second, right.second)};
    }


};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    SegmentTree SG;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout<<"#"<<test_case<<" ";
        cin>>n>>q;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        SG.init(0,n-1,1);
        for(int i=0;i<q;i++){
            cin>>c;
            if(c==0){
                cin>>idx>>x;
                arr[idx] = x;
                SG.change(0,n-1,1,idx);
            }else{
                cin>>l>>r;
                pair<int,int> res = SG.search(0,n-1,1,l,r-1);
                cout<<res.second-res.first<<" ";
            }
        }
        cout<<'\n';
        //cout<<"#"<<test_case<<" "<<ans<<'\n';
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}