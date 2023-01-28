#include <bits/stdc++.h>
using namespace std;
int tot;
map<int, int> alloc;
set<pair<int, int>> mem;

void init(int N) {
    mem.clear();
    alloc.clear();
    tot = N;
    mem.insert({N,0});
	return;
}

int allocate(int mSize) {
    auto it = mem.lower_bound({mSize,0});
    if(it == mem.end()) return -1;
    int freeSize = it->first, addr = it->second;
    mem.erase(it);
    alloc[addr] = mSize;
    if(freeSize > mSize) mem.emplace(freeSize-mSize,addr+mSize);
	return addr;
}

int release(int mAddr) {
    auto it = alloc.find(mAddr);
    if(it == alloc.end()) return -1;
    int size = alloc[mAddr];
    it = alloc.erase(it);
    int new_free=0, before_free=0;
    if(it == alloc.end()){
        new_free = tot - mAddr;
        before_free = tot - mAddr - size;
    }else{
        new_free += it->first - mAddr;
        before_free = it->first - mAddr - size;
    }
    if(before_free > 0){
        mem.erase({before_free, mAddr + size});
    } 
    if(it == alloc.begin()){
        mem.emplace(new_free,mAddr);
    }else{
        it--;
        new_free += (mAddr - it->first - it->second);
        if(new_free > 0) mem.emplace(new_free,it->first+it->second);
    }
	return size;
}
/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ALLOCATE 2
#define CMD_RELEASE 3

static bool run() {
	int q;
	scanf("%d", &q);

	int n, addr, size;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d", &n);
				init(n);
				okay = true;
				break;
			case CMD_ALLOCATE:
				scanf("%d %d", &size, &ans);
				ret = allocate(size);
				if (ans != ret)
					okay = false;
				break;
			case CMD_RELEASE:
				scanf("%d %d", &addr, &ans);
				ret = release(addr);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}