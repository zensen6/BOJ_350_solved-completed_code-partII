import sys
input = sys.stdin.readline

MAX = 1000000000
node = [[] for _ in range(501)]
ind = [0 for _ in range(501)]
check = [0 for _ in range(501)]
d = [0 for _ in range(501)]

n = int(input())
for i in range(1,n+1):
    li = list(map(int, input().split()))
    if li[1] != -1:
        ind[i]+=1
        s = len(li)
        for j in range(1,s-1):
            node[li[j]].append((li[0],i))
    else:
        d[i] = li[0]

q = []
ans = 0
for i in range(1,n+1):
    if ind[i] == 0:
        q.append(i)


while q:
    here = q.pop(0)
    for cost, next in node[here]:
        d[next] = max(d[next], d[here] + cost)
        ind[next] -= 1
        if ind[next] == 0:
            q.append(next)

for i in range(1,n+1):
    print(d[i])
