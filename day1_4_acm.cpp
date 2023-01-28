#include<stdio.h>
#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };
struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
int s;
Node* head;
Node* tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    s = 0;
    head = NULL;
    tail = NULL;
    return;
}

void addNode2Head(int data) 
{
    Node *nnode = getNode(data);
    if(s>0){
        nnode->next = head;
    }else{
        tail = nnode;
    }
    s++;
    head = nnode;
    return;
}

void addNode2Tail(int data) 
{
    Node *nnode = getNode(data);
    if(s==0){
        head = nnode;
        tail = nnode;
    }
    else{
        tail->next = nnode;
        tail = nnode;
    }
    s++;
    return;
}

void addNode2Num(int data, int num) 
{
    Node *nnode = getNode(data);
    if(s==0){
        head = nnode;
        tail = nnode;
    }else{
        Node *cur=head;
        Node *prev=head;
        if(num==1){
            nnode->next = head;
            head = nnode;
        }else{
            int i = 2;
            while(cur != NULL && i<=num){
                prev = cur; 
                cur = cur->next;
                i++;
            }
            if(num < s+1){
                nnode->next = cur;
                prev->next = nnode;
            }else{
                if(cur == NULL){
                    prev->next = nnode;
                    tail = nnode;
                }else{
                    cur->next = nnode;
                    tail = nnode;
                }
            }
        }
    }
    s++;
    return;
}

void removeNode(int data) 
{
    s=0;
    Node* cur = head;
    Node* nhead = NULL;
    while(cur != NULL){
        if(cur->data != data){
            Node *nnode = getNode(cur->data);
            if(nhead == NULL){
                nhead = nnode;
            }else{
                tail->next = nnode;
            }
            tail = nnode;
            s++;
        }
        cur = cur->next;
    }
    head = nhead;

    return;
}

int getList(int output[MAX_NODE]) 
{
    int i=0;
    Node* cur = head;
    while(cur != NULL){
        output[i++] = cur->data;
        cur = cur->next;
    }
    return s;
}


static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	//freopen("sll_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}