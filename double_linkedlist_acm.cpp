#include <stdio.h>
enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };
#define MAX_NODE 10000

static int nodeCnt;
static int s;

struct Node {
	int data;
	Node* next;
    Node* prev;
};

Node node[MAX_NODE];

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
    node[nodeCnt].prev = nullptr;
	return &node[nodeCnt++];
}

static Node* head;
static Node* tail;


void init()
{
    s = 0;
    head = nullptr;
    tail = nullptr;
    return;
}

void addNode2Head(int data) 
{
    Node *nnode = getNode(data);
    if(s>0){
        nnode->next = head;
        nnode->next->prev = nnode;
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
        tail->next->prev=tail;
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
            nnode->next->prev = nnode;
            head = nnode;
        }else{
            int i = 2;
            while(cur != nullptr && i<=num){
                prev = cur; 
                cur = cur->next;
                i++;
            }
            if(num < s+1){
                nnode->next = cur;
                cur->prev = nnode;
                prev->next = nnode;
                nnode->prev = prev;
            }else{
                if(cur == nullptr){
                    prev->next = nnode;
                    nnode->prev = prev;
                    tail = nnode;
                }else{
                    cur->next = nnode;
                    nnode->prev = cur;
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
    Node* nhead = nullptr;
    while(cur != nullptr){
        if(cur->data != data){
            Node *nnode = getNode(cur->data);
            if(nhead == nullptr){
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
    while(cur != nullptr){
        output[i++] = cur->data;
        cur = cur->next;
    }
    return s;
}

int findNode(int data){
    Node* cur=head;
    int i=1;
    while(cur!=nullptr){
        if(cur->data == data) return i;
        cur = cur->next;
        i++;
    }
    return i;
}

int getReversedList(int output[MAX_NODE]) 
{
    int i=0;
    Node* cur = tail;
    while(cur != nullptr){
        output[i++] = cur->data;
        cur = cur->prev;
    }
    return s;
}