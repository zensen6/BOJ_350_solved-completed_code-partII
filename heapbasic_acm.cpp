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
#include<queue>
#include<algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>

class MaxHeap {
#define parent  (i >> 1)
#define left	(i << 1)
#define right   (i << 1 | 1)

	static constexpr size_t MAX_N = 100000;

public:
    int data[MAX_N + 1];
	size_t size;
	MaxHeap() = default;

	void init() {
		size = 0;
	}

	// x 삽입
	void push(int x) {
		data[++size] = x;
		for (int i = size; parent != 0 && data[parent] < data[i]; i >>= 1) {
			std::swap(data[parent], data[i]);
		}
	}

	// 최대값 리턴
	int top() const {
		assert(size != 0);
		return data[1];
	}

	// 최대값 삭제
	void pop() {
		assert(size != 0);
		data[1] = data[size--];
		for (size_t i = 1; left <= size;) {
			const size_t max_child = left == size || data[left] > data[right] ? left : right;
			if (data[max_child] > data[i]) {
				std::swap(data[max_child], data[i]);
				i = max_child;
			} else {
				break;
			}
		}
	}

#undef parent
#undef left
#undef right
};

using namespace std;

int n,x,y;

string str;

vector<int> proc(){
    cin>>n;
    vector<int> ans;
    MaxHeap pq;
    pq.init();
    cin.ignore();
    
    for (int i = 0; i < n; ++i) {
      getline(cin, str);
      vector <string> words;
      stringstream stream(str);
      string word;
      
      while (getline(stream, word, ' ')) {
        words.push_back(word);
      }
      
      if (words.size() == 2) pq.push(stoi(words[1]));
      else{
          if(pq.size == 0) ans.push_back(-1);
          else{
              ans.push_back(pq.top());
              pq.pop();
          }
      }
    }
    return ans;

}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
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
        vector<int> ans = proc();
        cout<<"#"<<test_case<<" ";
        for(auto &p: ans) cout<<p<<" ";
        cout<<'\n'; 
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}