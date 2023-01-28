#include <iostream>
#include <cmath>

using namespace std;

#define MAX_NODE 100000
#define MAX_EXP 17 //round up log2(100000)

struct Node {
	int data;
	Node* next;
};

int cntTotalNode = 0;

Node nodes[MAX_NODE + 1];

Node children[MAX_NODE + 1]; //head of linked list to store children
Node* tail[MAX_NODE + 1]; //tail of linked list

Node* getNewNode(int data) {
	nodes[cntTotalNode].data = data;
	nodes[cntTotalNode].next = nullptr;

	return &nodes[cntTotalNode++];
}

long long parent[MAX_NODE + 1];
long long depth[MAX_NODE + 1];
long long max_level[MAX_NODE + 1]; //log2(depth) of each node
long long DP[MAX_NODE + 1][MAX_EXP]; //[n][k] : 2^k-th parent of node #n

long long deque[MAX_NODE + 1]; //for dfs & bfs

void getTree(int root) { //calculate DP[][]
	int top = -1; //top of stack(deque)

	deque[++top] = root;

	int v;

	//dfs
	while (top >= 0) {
		v = deque[top--];

		depth[v] = depth[parent[v]] + 1;

		DP[v][0] = parent[v];

		max_level[v] = (int)log2(depth[v]);

		for (int d = 1; d <= max_level[v]; d++) {
			DP[v][d] = DP[DP[v][d - 1]][d - 1];
		}

		for (Node* n = children[v].next; n != nullptr; n = n->next) {
			deque[++top] = n->data;
		}
	}
}

long long dist(int v1, int v2) { //get dist between v1, v2 by LCA(least common ancestor)
	long long prevDepth1 = depth[v1];
	long long prevDepth2 = depth[v2];

	long long i;

	if (depth[v1] < depth[v2]) {
		long long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}

	for (i = max_level[v1]; depth[v1] > depth[v2]; --i) {
		if (depth[DP[v1][i]] >= depth[v2]) {
			v1 = DP[v1][i];
		}
	}

	while (v1 != v2) {
		for (i = max_level[v1]; ; --i) {
			if (DP[v1][i] != DP[v2][i] || i == 0) {
				v1 = DP[v1][i];
				v2 = DP[v2][i];
				break;
			}
		}
	}

	return prevDepth1 + prevDepth2 - depth[v1] * 2;
}

long long BFSlen() {
	//set data for root(node 1)
	parent[1] = 0;
	depth[1] = 0;
	max_level[1] = 0;
	DP[1][0] = 0;

	//calculate DP[][]
	for (Node* n = children[1].next; n != nullptr; n = n->next) {
		getTree(n->data);
	}

	long long result = 0; //total distance

	//front & rear of queue (deque[])
	int front = 0;
	int rear = front; 

	deque[rear++] = 1;

	long long v, prev = 1;

	//bfs
	while (front < rear) {
		v = deque[front++];

		result += dist(v, prev);
		prev = v;

		for (Node* n = children[v].next; n != nullptr; n = n->next) {
			deque[rear++] = n->data;
		}
	}

	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	Node* newNode;

	int n;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;

		//init
		cntTotalNode = 0;

		for (int i = 1; i <= n; i++) {
			children[i].next = nullptr;
			tail[i] = &children[i];
		}

		//get input & set parent, children
		for (int i = 2; i <= n; i++) {
			cin >> parent[i];

			newNode = getNewNode(i);

			tail[parent[i]]->next = newNode;
			tail[parent[i]] = newNode;
		}

		cout << "#" << test_case << " " << BFSlen() << endl;
	}

	return 0;
}