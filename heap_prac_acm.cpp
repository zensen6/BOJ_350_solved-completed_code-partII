#include<iostream>
using namespace std;
#define MAX_N 100001

struct Node {
	int value;
	int id;

	bool operator >(const Node& rhs) const {
		return value != rhs.value ? value > rhs.value : id < rhs.id;
	}
};

void swap(Node *a, Node *b){
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}


struct PQ {
#define parent (i >> 1)
#define left (i << 1)
#define right (i << 1 | 1)


	Node heap[MAX_N + 1];
	int index[MAX_N];
	int size;

	void init() {
		size = 0;
	}

	void push(int id, int score) {
		heap[++size] = {score,id};
		for (int i = size; parent != 0 && heap[i] > heap[parent]; i >>= 1) {
			swap(&heap[i], &heap[parent]);
		}
	}

// 최대값 삭제
	void pop() {
		heap[0] = heap[size--];
		for (int i = 0; left <= size;) {
			const int max_child = left == size || heap[left] > heap[right] ? left : right;
			if (heap[max_child] > heap[i]) {
				swap(&heap[max_child], &heap[i]);
				i = max_child;
			} else {
				break;
			}
		}
	}

	// 최대값(최대값이 여러 개일 경우 id가 가장 작은 값)을 리턴한다.
	Node top() const {
		return heap[1];
	}

	// 최대값(최대값이 여러 개일 경우 id가 가장 작은 값)을 제거한다.

};



static PQ pq;

void init(){
    pq.init();
};
void addUser(int uID, int income){
    pq.push(income,uID);
};
int getTop10(int result[10]){
    int s = 0;
	int score[10];
    while(pq.size > 0){
        result[s] = pq.top().id;
		score[s] = pq.top().value;
		s++;
		pq.pop();   
    }
	for(int i=0;i<s;i++){
		pq.push(result[s],score[s]);
	}
    return s;

};
int main(){
	int n;
	int x,id;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>id>>x;
		pq.push(id,x);
	}
	while(pq.size>0){
		cout<<pq.top().id<<" "<<pq.top().value<<'\n';
		pq.pop();
	}
}